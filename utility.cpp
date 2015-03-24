#include"utility.h"

//-----------------------------------------------------------------------------------
//用于调用<algorithm>里面sort的函数 ,比较对象是t_AnomalyScore
//-----------------------------------------------------------------------------------
int CmpAnomalyScore(t_AnomalyScore A,t_AnomalyScore B)
{
    return (A.score_) > (B.score_);
}

//-----------------------------------------------------------------------------------
//评估算法的精确度
//-----------------------------------------------------------------------------------
double CalculatePrecision(std::vector<t_AnomalyScore>* anomaly_score)
{
    return 0.0;
}

//-----------------------------------------------------------------------------------
//计算欧式距离
//-----------------------------------------------------------------------------------
double CalculateEulerDistance(t_Center A,t_Data B)
{
    double euler_distance = 0.0;
    //计算平方和距离
    for( int i = 0 ; i < B.attribute_num_ ; i++)
    {
        euler_distance += pow( (A.attribute_.at(i) - B.attribute_.at(i)),2);
    }
    euler_distance = sqrt(euler_distance);
    return euler_distance;
}

//-----------------------------------------------------------------------------------
//提取候选数据集合
//-----------------------------------------------------------------------------------
void SetCandidateDataSet(double percentage,
                         std::vector<t_Data>*source_data_set,
                         std::vector<t_AnomalyScore>*anomaly_set,
                         std::vector<t_Data>*target_data_set)
{   //候选数据集合的数量
  int candidate_num = floor(anomaly_set->size() * percentage);
  for( int i = 0;  i < candidate_num-1  ; i++)
  {

      int anomaly_index = anomaly_set->at(i).data_index_;
      t_Data temp = source_data_set->at(anomaly_index);
      target_data_set->push_back(source_data_set->at(anomaly_index));
      std::cout<<temp.data_class_<<std::endl;
  }

  for( int i = source_data_set->size() -1 ;  i >= source_data_set->size();
       i--)
  {

      int anomaly_index = anomaly_set->at(i).data_index_;
      t_Data temp = source_data_set->at(anomaly_index);
      target_data_set->push_back(source_data_set->at(anomaly_index));
      std::cout<<temp.data_class_<<std::endl;
  }
}


//-----------------------------------------------------------------------------------
//读取配置信息
//-----------------------------------------------------------------------------------
t_Configure SetConfiguraion(char* folder_name)
{
    std::fstream fin(folder_name,std::ios::in);

    //open the config file
    if( !fin.is_open() )
    {
        std::cerr<<"error:could not open"<<folder_name<<"!"<<
        std::endl;
        exit(-1);
    }

    //read configuration from the config file
    t_Configure config;
    while(!fin.eof())
    {
        char* status = new char[20];
       //read status
        fin>>status;

        //read parameter
        if( std::string(status) == std::string( "CONFIGURATION_NUM") )
        {
            std::string discared1,discared2,file_name;

            fin>>discared1>>discared2>>file_name;
            config.data_file_ = new char(strlen(file_name.c_str()) + 1);
            strcpy(config.data_file_,file_name.c_str());

            file_name.clear();
            fin>>discared1>>discared2>>file_name;
            config.score_file_ = new char(strlen(file_name.c_str()) + 1);
            strcpy(config.score_file_,file_name.c_str());

            file_name.clear();
            fin>>discared1>>discared2>>file_name;
            config.cluster_file_ = new char(strlen(file_name.c_str()) + 1);
            strcpy(config.cluster_file_,file_name.c_str());

            file_name.clear();
            fin>>discared1>>discared2>>file_name;
            config.lof_file_1_ = new char(strlen(file_name.c_str()) + 1);
            strcpy(config.lof_file_1_,file_name.c_str());

            file_name.clear();
            fin>>discared1>>discared2>>file_name;
            config.lof_file_2_ = new char(strlen(file_name.c_str()) + 1);
            strcpy(config.lof_file_2_,file_name.c_str());

            fin>>discared1>>discared2>>config.class_num_;
            fin>>discared1>>discared2>>config.dimension_size_;
            fin>>discared1>>discared2>>config.sample_size_;
            fin>>discared1>>discared2>>config.tree_num_;
            fin>>discared1>>discared2>>config.cluster_num_;
            fin>>discared1>>discared2>>config.bin_width_;
        }

        //read all class proportation
        if( std::string(status) == std::string("PROPORTION_NUM"))
        {
            for( int unsigned i = 0 ; i < config.class_num_; i++)
            {
                t_Proportion proportion;
                fin>>proportion.class_label_>>proportion.proportion_;
                proportion.class_num_ = 0;
                proportion.r_ = DBL_MAX;//set r_ DBL_MAX
                proportion.is_discovered_ = false;
                config.p_set.push_back(proportion);
            }
        }
        delete status;
    }

    //return configuration data
    return config;
}

//-----------------------------------------------------------------------------------
//计算欧式距离
//-----------------------------------------------------------------------------------
double CalculateEularDisntance(t_Data a,t_Data b)
{
    int dimension = a.attribute_num_;
    double distance = 0.0;
    //计算欧式距离
    for(int i = 0 ; i < dimension; i++)
    {
        distance += (a.attribute_[i] - b.attribute_[i])
                         *(a.attribute_[i] - b.attribute_[i]);
    }
    distance = sqrt(distance);
    return distance;
}

//-----------------------------------------------------------------------------------
//距离的比较
//-----------------------------------------------------------------------------------
int CmpDistance(t_Distance a, t_Distance b)
{
    return a.distance_ < b.distance_;
}

//-----------------------------------------------------------------------------------
//r 比较
//-----------------------------------------------------------------------------------
int CmpR(double a,double b)
{
    return a < b;
}

//-----------------------------------------------------------------------------------
//比较lof
//-----------------------------------------------------------------------------------
int CmpLOF(t_Data a, t_Data b)
{
    return a.lof_< b.lof_;
}


std::vector<t_Data> SetCandidateSet(std::vector<t_Data> data_set, int num)
{
  std::vector<t_Data> candidate_set;
  for (unsigned i = 0 ; i < num ; i++)
    {
      candidate_set.push_back(data_set.at(i));
    }
  return candidate_set;
}
