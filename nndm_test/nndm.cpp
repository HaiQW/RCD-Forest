#include "nndm.h"

/** NNDM construct function */
NNDM::NNDM(std::vector<t_Data>data_set,
           std::vector<t_Proportion>p_set,
           int data_size,
           int dimension) {
  /*initilize member viable*/
  data_set_ = data_set;
  p_set_ = p_set;
  data_size_ = data_size;
  dimension_ = dimension;
  class_num_ = p_set.size();
  nn_.resize(data_size);

  distance_matrix_.resize(data_size);
  for (int i = 0; i < data_size; i++)
    {
      distance_matrix_[i].resize(data_size);
    }

  init();
}

/** NNDM destruct function*/
NNDM::~NNDM()
{
  for (int i = 0 ;i < data_size_ ;i++)
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
  //计算距离矩阵
  CalculateDistance();
  //距离举证排序,计算K 距离
  CalculateKDistance();
  //计算NN
  CalculateNN();
}

/** return dinstance matrix*/
std::vector<std::vector<t_Distance> > NNDM::GetDistanceMatrix()
{
  return distance_matrix_;
}

/** calculate data numbers in every class*/
void NNDM::CalculateClassNum() {
  for (unsigned int i = 0; i < p_set_.size(); i++)
    {
      p_set_[i].class_num_ = ceil(p_set_[i].proportion_ * data_size_);
    }
}

/** calculate distance of every two data instance*/
void NNDM::CalculateDistance()
{
  //第一重循环
  for (int i = 0; i < data_size_; i++)
    {
      //第二重循环
      for (int j = i; j < data_size_; j++)
        {
          //计算欧式距离
          t_Distance distance_a,distance_b;
          distance_a.distance_ = CalculateEularDisntance(data_set_[i],
                                                         data_set_[j]);
          distance_b.distance_ = distance_a.distance_;
          distance_a.node_a_ = i;
          distance_a.node_b_ = j;
          distance_b.node_a_ = j;
          distance_b.node_b_ = i;
          distance_matrix_[i][j] = distance_a;
          distance_matrix_[j][i] = distance_b;
        }
    }
}

/** calculate k-distance*/
void NNDM::CalculateKDistance( )
{
  //根据distance排序
  for (int i = 0; i < data_size_; i++)
    {
      std::sort(distance_matrix_[i].begin(),
                distance_matrix_[i].end(),
                CmpDistance);
    }
  //计算r
  for (int i = 1; i < class_num_; i++)
    {
      std::vector<double>r;
      int num = p_set_[i].class_num_;
      if (num < 1) continue;
      //k近邻
      for (int j = 0; j < data_size_; j++)
        {
          std::cout<<j<<std::endl;
          r.push_back(distance_matrix_[j][num].distance_);
        }
      //这里错了
      std::sort(r.begin(), r.end(), CmpR);
      p_set_[i].r_ = r[0];
      r.clear();
    }

  //设置主要类的r
  double r_max = DBL_MIN;
  for (int i = 1; i < class_num_; i++)
    {
      if (p_set_[i].r_ > r_max && p_set_[i].r_ != DBL_MAX)
        {
          r_max = p_set_[i].r_;
        }
    }
  p_set_[0].r_ = r_max;
}

/** calculate nn number */
void NNDM::CalculateNN()
{
  //计算每一个类别NN 的数目
  for (int i = 0; i < class_num_; i++)
    {
      //类数目小于一跳出循环
      //if( p_set_[i].class_num_ <= 1) continue;
      //计算每一个instance 的nn值
      for (int j = 0; j < data_size_; j++)
        {
          double r = p_set_[i].r_;
          t_NN nn;

          //可以用二分查找计算 nn的个数
          int begin = 0;
          int end ,index;
          end = data_size_ - 1;
          index = (begin + end) /2;
          while (abs(end - begin) != 1)
            {
              if (r <= distance_matrix_[j][index].distance_)
                {
                  end = index;
                }
              else
                {
                  begin = index;
                }
              index = (begin + end)/2;
            }

          nn.num_.push_back(begin+1);
          nn.class_label_ = i;
          nn_[j].push_back(nn);
        }
    }
}


/** find rarecategory class*/
void NNDM::DiscoverClass()
{
  int class_discovered = 0;//number of discovered class
  int count = 0;//number of oracle label asked

  while (class_discovered < class_num_)
    {
      double r_min = DBL_MAX;
      int index_s;
      /*find r_min*/
      for (int i = 0; i < class_num_; i++)
        {
          /*if the class has not been discovered yet*/
          if (p_set_[i].is_discovered_ == false)
            {
              if (p_set_[i].r_ < r_min)
                {
                  r_min = p_set_[i].r_;
                  index_s = i;
                }
            }
          else
            {
              continue;
            }
        }

      /*enlarge search radium*/
      for (int t = 1; t < data_size_; t++)
        {
          //计算分数score
          int selected_score_max = DBL_MIN;
          int selected_index = -1;
          for (int i = 0; i < data_size_; i++)
            {
              //改instance nn的个数
              int nn_i =  nn_[i][index_s].num_[0];
              double s_max = -1;

              //如果t已经被搜索过
              if (data_set_[i].find_label_ == 1)
                {
                  continue;
                }
              //搜索nn空范围里面的instance,求score
              for (int j = 0;
                   j < data_size_&& distance_matrix_[i][j].distance_ < p_set_[index_s].r_ * t;
                   j++)
                {
                  int index_j = distance_matrix_[i][j].node_b_;
                  int nn_j = nn_[index_j][index_s].num_[0];
                  if ((nn_i - nn_j) > s_max)
                    {
                      s_max = nn_i - nn_j;
                    }
                }


              //寻找score 最大值的instance 访问oracle数据库
              if(s_max >= selected_score_max)
                {
                  selected_score_max = s_max;
                  selected_index = i;
                }
            }

          //询问oracle 数据库
          int find_class = data_set_[selected_index].data_class_ ;
          data_set_[selected_index].find_label_ = 1;
          for(int k = 1; k < nn_[selected_index][index_s].num_[0]; k++)
            {
              data_set_[distance_matrix_[selected_index][k].node_b_]
                  .find_label_ = 1;
            }
          //访问次数+1
          count++;
          //发现了一个新的类别之后要把周围的数据全部注释掉
          if (false == p_set_[find_class].is_discovered_ )
            {
              p_set_[data_set_[selected_index].data_class_ ]
                  .is_discovered_ = true;
              //发现类的个数+1
              class_discovered++;
              std::cout<<"发现新的类的下标:"<<find_class<<std::endl;
              std::cout<<"询问数据库的次数："<<count<<std::endl;
              std::cout<<"发现类的个数："<<class_discovered<<std::endl;
              //跳出扩大t范围的for循环
              break;
            }
        }
    }
}
