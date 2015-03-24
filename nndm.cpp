#include "nndm.h"

/** NNDM construct function */
NNDM::NNDM(std::vector<t_Data>data_set,
           std::vector<t_Proportion>p_set,
           int data_size,
           int class_num,
           int dimension) {
  /*initilize member viable*/
  data_set_ = data_set;
  p_set_ = p_set;
  size_ = data_size;
  dimension_ = dimension;
  class_num_ = class_num;

}

/** NNDM destruct function*/
NNDM::~NNDM()
{
  for (int i = 0 ;i < size_ ;i++)
    {
      distance_matrix_[i].clear();
    }
  distance_matrix_.clear();
}

/** init configure function*/
void NNDM::init()
{
  //计算每一个类里面实例的个数
  CalculateClassNum();
  //计算NN
  CalculateNN();
}

/** calculate data numbers in every class*/
void NNDM::CalculateClassNum() {
  for (unsigned int i = 0; i < p_set_.size(); i++)
    {
      p_set_[i].class_num_ = ceil(p_set_[i].proportion_ * size_);
      p_set_[i].is_discovered_ = false;
    }
}

/**calculate r for every class*/
void NNDM::CalculateR()
{
   /*copy data example to data matrix*/
  for (int i = 0; i < size_; i++)
    {
      std::vector<double> attribute_i = data_set_[i].attribute_;
      vec ele_i(attribute_i);
      data_matrix_.insert_cols(i,ele_i);//at column i insert a column
    }

  /*find the maximum rare class num*/
  AllkNN knn(data_matrix_);
  knn.Search(size_ - 1, data_set_neigbour_, data_set_dis_);

  /*set r_i(i > 0) for every class and r_0 is the largest of r_i*/
  double r_0 = -DBL_MIN;
  for (int i = 1; i < class_num_; i++)
    {
      /*r_i is the smallest of k_i distance of all elements*/
      int k = p_set_[i].class_num_-1;
      rowvec kdistance_set_i = data_set_dis_.row(k-1);
      double r_i = kdistance_set_i.min();//row vector
      uvec index = find(kdistance_set_i == r_i);
      std::cout<<"i:"<<i<<std::endl;
      std::cout<<index[0]<<std::endl;
      p_set_[i].r_ = r_i;
      /*update r_0*/
      if (r_i > r_0)
        {
          r_0 = r_i;
        }
    }
  p_set_[0].r_ = r_0;
}



/** calculate nn number using range search*/
void NNDM::CalculateNN()
{
  /*copy neighbour distance to vector*/
  std::vector<std::vector<double> > dis_vec(size_);
  for ( int i = 0; i < size_; i++)
    {
      for(int j = 0; j < size_ - 1; j++)
        {
          dis_vec[i].push_back(data_set_dis_(j,i));
        }
    };
  nn_.resize(size_);//set size of nn_
  /*calculate knn number of every dimension i*/
  for (int i = 0; i < class_num_; i++)
    {
      double r_i= p_set_[i].r_;
      /*calculate knn in dimension i of every element j*/
      for (int j = 0; j < size_; j++)
        {
          /*smallset kdistance of dimension_i*/
          t_NN nn_j;
          vec distance_set_j(data_set_dis_.col(j));
          vec nn_set_j = distance_set_j.elem(find( distance_set_j <= r_i));
          int num = nn_set_j.n_elem;
          nn_j.class_label_ = i;
          nn_j.num_ = num ;
          nn_[j].push_back(nn_j);
        }
    }

  /*计算每一个element在每一个纬度每一个t扩展的distance的密度，2*/
  score_.resize(size_);
  /*every element*/
  for (int n = 0; n < size_; n++)
    {
      /*every dimension*/
      for (int d = 0; d < class_num_; d++)
        {
          t_S s_d;
          int s_max = 0;
          double r_d = p_set_[d].r_;
          int nn_n_d = nn_[n][d].num_;//kdistance number of element n
                                      //at dimension d
          int t = 1;
          double r_t = r_d * t;
          s_d.n_ = 0;
          /*has size_ - 1 neighbours*/
          for ( int k = 0;k < size_ - 1;k++)
            {
              /*todo tomorrow 10/5*/
              int index = data_set_neigbour_(k,n);
              int nn_k_d = nn_[index][d].num_;
              int s_temp = nn_n_d - nn_k_d;
              /*enlarge t*/
              if( t >= size_) break;
              if (data_set_dis_(k,n) > r_t)
                {
                  t++;
                  k--;
                  s_d.n_++;
                  r_t = r_d * t;
                  s_d.ts_.push_back(s_max);
                  continue;
                }
              if (s_temp > s_max)
                {
                  s_max = s_temp;
                }
            }
          score_[n].push_back(s_d);
        }
    }
}


/** find rarecategory class*/
void NNDM::DiscoverClass()
{
  std::vector<bool> data_asked(size_,false);
  std::vector<bool> class_discovered(class_num_,false);
  int candidate_num = size_;
  /*begin to find rare class*/
  int class_count = 0;
  int asked_count = 0;
  while (candidate_num > 0&&class_count < class_num_)
    {
      if (asked_count >= size_)
        {
          std::cout<<"stop asking label!"<<std::endl;
          break;
        }

      /*find r_i and s*/
      int s_index = -1;
      double s_i = -DBL_MAX;
      for (int s = 0; s < class_num_; s++)
        {
          if (class_discovered[s] == false &&
              p_set_[s].r_ > s_i)
            {
              s_index = s;
            }
        }

      int label = -1;//delete elements
      for (int t = 1; t < size_; t++)
        {
          //reset t
          int score_t = 0;
          int index_t = -1;
          /*begin to find max score in dimension s*/
          for (int j = 0; j < size_; j++)
            {
              int enlarge = t-1;
              if (t > score_[j][s_index].ts_.size())
                {
                  enlarge = score_[j][s_index].ts_.size() - 1;
                  continue;
                }
              if (score_[j][s_index].ts_[enlarge] >= score_t &&
                  data_asked[j] == false)
                {
                  score_t = score_[j][s_index].ts_[enlarge];
                  index_t = j;
                }
            }
          if(index_t < 0)
            {
              continue;
            }
          /*ask oracle label*/
          data_asked[index_t] = true;
          label = data_set_[index_t].data_class_;
          asked_count++;//increment asked_count by one
          candidate_num = candidate_num - nn_[index_t][label].num_ -1;
          /*set kdistance element false*/
          for (int k = 0; k < nn_[index_t][label].num_ - 1; k++)
            {
              int index = this->data_set_neigbour_(k,index_t);
              data_asked[index] = true;
            }
          if (class_discovered[label] == false)//find a new class
            {
              class_discovered[label] = true;
              class_count++;
              std::cout<<"asked_count:"<<asked_count<<std::endl;
              std::cout<<"class_count:"<<class_count<<std::endl;
              std::cout<<"class_index:"<<label<<std::endl;
              break;
            }
        }
    }
}
