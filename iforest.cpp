#include "iforest.h"
//------------------------------------------------------------------------------
//IForest带参数的构造函数
//------------------------------------------------------------------------------
IForest::IForest(int itrees_num,int itree_height,
                       int sample_num,
                       DataProcess* data_procession)
{
    //初始化成员变量
    sample_num_ = sample_num;
    itrees_num_ = itrees_num;
    data_procession_ = data_procession;
    data_num_ = data_procession->GetDataSet().size();
    //集体初始化itree指针，new 空间
    for( int i = 0 ; i < itrees_num_;i++)
    {
        iTree* itree = new iTree(data_procession,itree_height);
        itrees_set_.push_back(itree);
    }
}

//------------------------------------------------------------------------------
//IForest带参数的析构函数，释放new的空间
//------------------------------------------------------------------------------
IForest::~IForest()
{
    //释放itree指针所指的空间
    for( int i = 0 ; i < itrees_num_;i++)
    {
        delete itrees_set_.at(i);
    }
}

//------------------------------------------------------------------------------
//构建itree_num棵树，作为森林
//------------------------------------------------------------------------------
void IForest::BuidIforest()
{
    std::vector<t_Data> sample_data;
    for(int i = 0 ; i < itrees_num_ ; i++)
      {
        sample_data.clear();
        data_procession_->RandomSampling(sample_num_,&sample_data);
        itrees_set_[i]->BuildITree(&sample_data,itrees_set_[i]->GetRoot(),0);
        std::cout<<"No. "<<i<<" Compact Tree.";
      }
}

//------------------------------------------------------------------------------
//calculate all score in the forest
//------------------------------------------------------------------------------
std::vector<t_AnomalyScore> IForest::CalculateAllScore()
{
  int data_size = data_procession_->GetDataSize();
  std::vector<t_Data> data_set = data_procession_->GetNormalizedDataSet();
  std::vector<t_AnomalyScore> score_set;

  //caculate score
  for (unsigned i = 0 ; i < data_size ; i++ )
    {
      t_AnomalyScore score_temp;
      double length_temp = 0.0;
      t_Data data_temp = data_set[i];

      for ( unsigned j = 0 ; j < itrees_num_ ; j++ )
        {
          iTree* tree_temp = itrees_set_[j];
          t_INode* root_temp = tree_temp->GetRoot();
          length_temp += tree_temp->SearchInstance(data_temp,root_temp,0);
        }

      //put score temp to score array
      length_temp = length_temp / itrees_num_;
      score_temp.score_ = length_temp;
      score_temp.class_label_ = data_temp.data_class_;
      score_temp.data_index_ = i;
      score_set.push_back(score_temp);
    }
  return score_set;
}

//------------------------------------------------------------------------------
//计算搜索分数
//------------------------------------------------------------------------------
double IForest::CalculateScore(t_Data data_point)
{
    double total_score = 0.0;
    double average_score = 0.0;
    int data_num;
    data_num = data_num_;//尽量减少vector数组函数的调用

    for( int i = 0 ; i < itrees_num_ ; i++)
    {
        double score;
        t_INode* root;

        root = itrees_set_[i]->GetRoot();
        score = itrees_set_[i]->SearchInstance(data_point,root,0);
        total_score += score;
    }

    average_score = total_score/itrees_num_;
    return average_score;
}
