#ifndef UTILITY_H
#define UTILITY_H

#include<algorithm>
#include<fstream>
#include<iostream>
#include<map>
#include<string>
#include<math.h>
#include<float.h>
#include<string.h>

#include"data_struct.h"

//用于调用<algorithm>里面sort的函数，比较对象是t_CutPoint
int CmpCutPoint(t_CutPoint&A,t_CutPoint&B);

//用于调用<algorithm>里面sort的函数 ,比较对象是t_AnomalyScore
int CmpAnomalyScore(t_AnomalyScore A,t_AnomalyScore B);

//对聚类结果根据其距离聚类的中心进行排序
//int CmpClusterData(t_ClusterData A,t_ClusterData B);

//评估算法的精确度
double CalculatePrecision(std::vector<t_AnomalyScore>*anomaly_score);

//计算欧式距离
double CalculateEulerDistance(t_Center A,t_Data B);

//提取候选数据集合
void SetCandidateDataSet(double percentage,
                         std::vector<t_Data>*source_data_set,
                         std::vector<t_AnomalyScore>*anomaly_set,
                         std::vector<t_Data>*target_data_set);
//配置信息
t_Configure SetConfiguraion(char* folder_name );

//计算距离
double CalculateEularDisntance(t_Data a,t_Data b);

//距离比较
int CmpDistance(t_Distance a, t_Distance b);

//r 比较
int CmpR(double a,double b);

//比较lof
int CmpLOF(t_Data a, t_Data b);

std::vector<t_Data> SetCandidateSet(std::vector<t_Data> data_set,
                                    int num);

#endif // UTILITY_H
