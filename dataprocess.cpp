#include "dataprocess.h"
//------------------------------------------------------------------------------
//DataProcess的构造函数
//输入参数
//data_set:绑定的数据集合
//dimensions_range:数据集合每一个维度的范围
//bin_width:估计的带宽
//输出参数：
//------------------------------------------------------------------------------
DataProcess::DataProcess(std::vector<t_Data>data_set,
                         std::vector<t_Range> dimensions_range,
                         double bin_width,
                         int dimension_size)
{
    //成员变量初始化
    data_set_ = data_set;
    bin_width_ = bin_width;
    data_size_ = data_set.size();
    dimensions_range_ = dimensions_range;
    dimension_size_ = dimension_size;
    //DataProcess类初始化的时候需要执行的初始函数
    Init();
}

//------------------------------------------------------------------------------
//DataProcess的析构函数
//------------------------------------------------------------------------------
DataProcess::~DataProcess()
{

}

//------------------------------------------------------------------------------
//DataProcess集中初始化函数
//------------------------------------------------------------------------------
void DataProcess::Init()
{
    //初始化时间种子
    srand((unsigned)time(0));
}

//------------------------------------------------------------------------------
//返回数据集合
//------------------------------------------------------------------------------
std::vector<t_Data>  DataProcess::GetDataSet()
{
  return data_set_;
}

std::vector<t_Data> DataProcess::GetNormalizedDataSet()
{
  return data_set_normalized_;
}

int DataProcess::GetDataSize()
{
  return data_size_;
}

//------------------------------------------------------------------------------
//设置需要处理的数据集
//输入参数
//data_set: 需要进行处理的数据集合
//输出参数
//------------------------------------------------------------------------------
bool DataProcess::SetProcessDateSet(std::vector<t_Data> data_set)
{
    if ( data_set.size() > 0)
    {
        data_set_ = data_set;
        return true;
    }
    else
    {
        std::cerr<<"error:the input data set is empty!"<<std::endl;
        return false;
      }
}

//------------------------------------------------------------------------------
//归一化数据
//------------------------------------------------------------------------------
void DataProcess::NormalizeData()
{
  data_set_normalized_ = data_set_;
  for (int i = 0 ; i < dimension_size_; i++ )
  {
      //找每一个维度的最大最小值
      double min_temp = DBL_MAX,max_temp = -DBL_MAX ;

      for (int j = 0 ; j < data_size_ ;j++ )
      {
          double data_temp = data_set_[j].attribute_[i];

          if ( data_temp > max_temp )
          {
              max_temp = data_temp;
          }

          if ( data_temp < min_temp ){
              min_temp = data_temp;
          }
      }

      //归一化数据
      for ( int j = 0 ; j < data_size_ ;j++ )
      {
          //该attribute属性下的数据都相等，归一化为0
          if ( min_temp == max_temp )
          {
              data_set_normalized_[j].attribute_[i] = 0.0;
          }
          else {
              data_set_normalized_[j].attribute_[i] =
                  (data_set_[j].attribute_[i] - min_temp)/
                  (max_temp-min_temp);
          }
      }
  }
}

//------------------------------------------------------------------------------
//归一化数据
//输入参数
//target_data_set: 需要进行处理的数据集合
//输出参数
//source_data_set:归一化之后的数据集合
//------------------------------------------------------------------------------
void DataProcess::NormalizeData(std::vector<t_Data>*data_set)
{
    for (int i = 0 ; i < data_set->at(0).attribute_num_;i++ )
    {
        //找每一个维度的最大最小值
        double min_temp = DBL_MAX,max_temp = DBL_MIN ;

        for (int j = 0 ; j <data_set->size();j++ )
        {
            double data_temp = data_set->at(j).attribute_.at(i);

            if ( data_temp > max_temp )
            {
                max_temp = data_temp;
            }

            if ( data_temp < min_temp ){
                min_temp = data_temp;
            }
        }

        //归一化数据
        for ( int j = 0 ; j < data_set->size();j++ )
        {
            //该attribute属性下的数据都相等，归一化为0
            if ( min_temp == max_temp )
            {
                data_set->at(j).attribute_.at(i) = 0.0;
            }
            else {
                data_set->at(j).attribute_.at(i) =
                (data_set->at(j).attribute_.at(i) - min_temp)
                /abs(min_temp-max_temp);
            }
        }
    }
}
//------------------------------------------------------------------------------
//随机取样
//------------------------------------------------------------------------------
 void DataProcess::RandomSampling (int sample_num,
                                  std::vector<t_Data>*sample_data_set )
 {
    //std::random_shuffle(source_data_set->begin(),source_data_set->end());
    srand(unsigned(0));
    //QueryPerformanceFrequency(&seed);
    //QueryPerformanceCounter(&seed);
    //srand(seed.QuadPart);

     //随机n个数
    for ( int i = 0 ; i < sample_num ; i++ )
    {
        int index = rand() % data_size_;
        sample_data_set->push_back(data_set_normalized_[index]);
    }
 }

//------------------------------------------------------------------------------
//重新设置带宽
//------------------------------------------------------------------------------
bool DataProcess::SetBinWidth(double bin_width)
{
    if ( bin_width > 0 )
    {
        bin_width_ = bin_width;
        return true;
    }
    else
    {
        std::cerr<<"error:bin width is not resonable!"<<std::endl;
        return false;
    }
}

//------------------------------------------------------------------------------
//数据分成两部分:左半部分，又半部分
//输入参数
//source_data: 将要分割的数据集合
//输出参数
//dimension_index:分割的维度索引
//split_value:分割点的值
//target_left_set：分割后小于分割值的数据集
//target_right_set:分割后大于分割值的数据集
//------------------------------------------------------------------------------
bool DataProcess::DeterministicSplitDataSet(std::vector<t_Data>* target_left_set,
                                            std::vector<t_Data>*target_right_set,
                                            int&dimension_index,
                                            double&split_point,
                                            std::vector<t_Data>*source_data_set)
{
    double best_score = LONG_MIN;

    //if the source data set is empty,reture false
    if ( 0 == source_data_set->size())
    {
        return false;
    }

    dimension_index = rand() % dimension_size_;
#if 1
    //caculate best split point in the random dimension
    for ( double i = dimensions_range_.at(dimension_index).left_margin_;
          i<= dimensions_range_.at(dimension_index).right_margin_;
          i = i + bin_width_ )
    {
         double score_temp;
         CalculateSplitScore(score_temp,i,source_data_set,dimension_index);
         if ( score_temp > best_score )
         {
             best_score = score_temp;
             split_point = i;
         }
    }
#endif
// random split
#if 0
  split_point = (rand()%1000)/1000.0;
#endif
  //调用SplitDataSet函数，将source_data_set，分割成两部分
  return SplitDataSet(target_left_set,target_right_set,split_point,
                      dimension_index,source_data_set);
}

//------------------------------------------------------------------------------
//计算数据集合在某一个维度上面的方差
//------------------------------------------------------------------------------
double DataProcess::CalculateVariance(std::vector<t_Data>* data_set)
{
    int dimension_num = data_set->at(0).attribute_num_;
    int size = data_set->size();
    double variance = 0.0;
    //求和
    std::vector<double>sum(dimension_num,0.0);
    std::vector<double>avg(dimension_num,0.0);

    for ( int i = 0 ; i < size ; i++)
    {
        for( int j = 0 ; j < dimension_num; j++)
        {
           sum.at(j) = sum.at(j) + data_set->at(i).attribute_.at(j)/size;
        }
    }

    for ( int i = 0 ; i < size ; i++)
    {
        double distance_single = 0.0;
        for( int j = 0 ; j < dimension_num; j++)
        {
            distance_single += pow(data_set->at(i).attribute_.at(j) - sum.at(j),2);
        }
        variance += sqrt(distance_single);
    }
    variance = variance/size;
    return variance;

}
//***************************************
//protected 函数
//***************************************

//------------------------------------------------------------------------------
//计算某一分割点分割的值
//输入参数
//split_point: 分割的点的值
//data_set: 待分割的数据集合
//dimension_index: 待分割维度的索引
//输入参数
//split_score：分割的打分
//------------------------------------------------------------------------------
void DataProcess::CalculateSplitScore(double &split_score,double split_point,
                                      std::vector<t_Data>*data_set,int dimension_index)
{
    double left_sum = 0.0 ,right_sum = 0.0,left_avg = 0.0,right_avg = 0.0,
                left_var = 0.0 ,right_var = 0.0,total_avg = 0.0,total_var = 0.0;
    int left_denominator = 0 ,right_denominator = 0,total_denominator = 0;
    std::vector<double> left,right;

    //求左右split_point 左右两边的sum
    for ( unsigned i = 0 ; i < data_set->size(); i++ )
    {
        double temp = data_set->at(i).attribute_.at(dimension_index);
        if( temp  < split_point){
            left_sum += temp;
            left.push_back(temp);

        }
        else
        {
            right_sum += temp;
            right.push_back(temp);
        }
    }

    //计算分母大小，如果size<=0 ，则分母为0
    left_denominator = left.size()>0 ? left.size() : 1;
    right_denominator = right.size()>0 ? right.size() : 1;
    total_denominator = data_set->size()>0 ? data_set->size() : 1;

    //求左右split_point 左右两边的avg
    left_avg = left_sum / left_denominator;
    right_avg = right_sum / right_denominator;
    total_avg = (left_sum + right_sum)/total_denominator;

    //计算左半边的方差和
    for ( unsigned i = 0 ; i < left.size();i++ )
    {
        double temp_var = pow((left[i] - left_avg),2);
        left_var += temp_var;
        total_var += temp_var;
    }

    //计算右半边的方差和
    for ( unsigned i = 0 ; i < right.size();i++ )
    {
        double temp_var = pow((right[i] - right_avg),2);
        right_var += temp_var;
        total_var += temp_var;
    }

    //计算方差
    total_var = total_var/total_denominator;

    //计算分割值split_score
    split_score = total_var - (left_var +  right_var) / total_denominator;
    //split_score = split_score / total_var;
}

//------------------------------------------------------------------------------
//根据分割点split_point,分割维度dimension_index
//把数据分为左右两个数据集合,left_data_set,right_data_set
//------------------------------------------------------------------------------
bool DataProcess::SplitDataSet(std::vector<t_Data>*left_data_set,
                               std::vector<t_Data>*right_data_set,
                               double split_point,
                               int dimension_index,
                               std::vector<t_Data>*source_data_set)
{
    //将数据集合分割为两个部分
    for ( unsigned i = 0 ; i < source_data_set->size() ; i++ )
    {
        if (source_data_set->at(i).attribute_.at(dimension_index)
            < split_point)
        {
            left_data_set->push_back(source_data_set->at(i));
        }
        else
        {
            right_data_set->push_back(source_data_set->at(i));
        }
    }
    //检测是否分割
    if ( 0 != left_data_set->size()
         && 0!= right_data_set->size()
         && 0 != source_data_set->size() )
    {
        return true;
    }
    else
    {
        return false;
    }
}
