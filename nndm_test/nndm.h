#ifndef NNDM_H
#define NNDM_H

#include <iostream>
#include <algorithm>

#include "file.h"
#include "utility.h"

class NNDM
{
public:
  //构造函数
  NNDM(std::vector<t_Data>data_set,std::vector<t_Proportion>p_set,int data_size,
       int dimension);
  //析构函数
  ~NNDM();
public:
  //集体初始化函数
  void init();
  std::vector<std::vector<t_Distance> > GetDistanceMatrix();
  //发现稀有类
  void DiscoverClass();
protected:
  //计算每两个物体之间的距离
  void CalculateDistance();
  //计算R
  void CalculateR();
  //k距离
  void CalculateKDistance();
  //计算每一个class 里面实例的个数
  void CalculateClassNum();
  //计算NN 数量
  void CalculateNN();
private:
  //先验数据，比例值
  std::vector<t_Proportion> p_set_;
  //数据集合
  std::vector<t_Data> data_set_;
  //距离矩阵
  std::vector<std::vector<t_Distance> >distance_matrix_;
  //数据集合的个数n
  int data_size_;
  //数据的维度
  int dimension_;
  //类的个数
  int class_num_;
  //nn数目
  std::vector<std::vector<t_NN> >nn_;
};

#endif // NNDM_H
