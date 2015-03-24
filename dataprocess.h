#ifndef DATAPROCESS_H
#define DATAPROCESS_H

#include<vector>
#include<iostream>
#include<algorithm>
#include<time.h>
#include<climits>

#include"utility.h"
#include "data_struct.h"

class DataProcess
{
public:
    //构造函数
    DataProcess(std::vector<t_Data> data_set,
                std::vector<t_Range> dimensions_range,
                double bin_width,
                int dimension_size);
    //析构函数
    ~DataProcess();

 public:
     //随机取样
     void RandomSampling(int sample_num,
                         std::vector<t_Data>*sample_data_set);

     //返回数据集合
     std::vector<t_Data> GetDataSet();

     //返回数据集合
     std::vector<t_Data> GetNormalizedDataSet();

     //return data size
     int GetDataSize();

    //集中初始化有意义的数据
     void Init();

    //设置类中绑定的数据集
     bool SetProcessDateSet(std::vector<t_Data> data_set);

    //规格化数据集中的数据范围
     void NormalizeData();

    //规格化数据集中的数据范围
     void NormalizeData(std::vector<t_Data>*data_set);

    //重新设置带宽
     bool SetBinWidth(double bin_width);

    //决定性地将数据分成两部分:左半部分，又半部分
     bool DeterministicSplitDataSet(std::vector<t_Data>* target_left_set,
                                    std::vector<t_Data>*target_right_set,
                                    int&dimension_index,double&split_value,
                                    std::vector<t_Data>*source_data);

     //计算数据集合在某一个维度上面的方差
     double CalculateVariance(std::vector<t_Data>* data_set);

 protected:
    //根据分割点split_point,分割维度dimension_index
    //把数据分为左右两个数据集合,left_data_set,right_data_set
     bool SplitDataSet(std::vector<t_Data>*left_data_set,
                       std::vector<t_Data>*right_data_set,
                       double split_point,
                       int dimension_index,
                       std::vector<t_Data>*source_data_set);

    //计算维度的分割值,估计波峰波谷的个数
    void CalculateDimensionScore(std::vector<t_CutPoint>*cut_points,
                                 double& dimension_score,
                                 std::vector<t_KernelDensity>*kernel_estimation);

    //计算分割点split_point 的分数,返回值是分割分数
    void CalculateSplitScore(double &split_score,double split_point,
                             std::vector<t_Data>*data_set,int dimension_index);

    //Histogram 密度估计
    void HistogramEstimateData(std::vector<t_Range>*dimensions_range ,
                               std::vector<t_Data>*source_data);

    //核密度估计
    void EstimateKernelDensity(std::vector<t_KernelDensity>*kernel_density,
                               std::vector<t_Data> data_set,
                               int dimemsion_index,
                               double bin_width);

 private:
     //直方图以及和密度估计的带宽
     double bin_width_;

     //绑定的数据集合
     std::vector<t_Data> data_set_;

     //数据的个数
     int data_size_;

     //数据的纬度
     int dimension_size_;
     //每一个维度的数据值范围
     std::vector<t_Range> dimensions_range_;

     //normalized Data
     std::vector<t_Data> data_set_normalized_;
};
#endif // DATAPROCESS_H
