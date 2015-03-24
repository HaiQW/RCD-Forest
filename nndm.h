#ifndef NNDM_H
#define NNDM_H

#include <iostream>
#include <algorithm>
#include <math.h>
#include <pca.h>
#include <mlpack/methods/kmeans/kmeans.hpp>
#include <mlpack/methods/neighbor_search/neighbor_search.hpp>

#include "file.h"
#include "utility.h"

using namespace arma;
using namespace mlpack;
using namespace mlpack::kmeans;
using namespace mlpack::neighbor;

class NNDM
{
public:
  //构造函数
  NNDM(std::vector<t_Data>data_set,
       std::vector<t_Proportion>p_set,
       int data_size,
       int class_num,
       int dimension);
  //析构函数
  ~NNDM();
    void CalculateR();
public:
  //集体初始化函数
  void init();
  std::vector<std::vector<t_Distance> > GetDistanceMatrix();
  //发现稀有类
  void DiscoverClass();
public:

  void CalculateKDistance();
  //计算每一个class 里面实例的个数
  void CalculateClassNum();
  //计算NN 数量
  void CalculateNN();
private:
  //先验数据，比例值
  std::vector<t_Proportion> p_set_;
  //距离矩阵
  std::vector<std::vector<t_Distance> >distance_matrix_;
  //数据集合的个数n
  int size_;
  //数据的维度
  int dimension_;
  //类的个数
  int class_num_;
  //nn数目
  std::vector<std::vector<t_NN> >nn_;
   std::vector<t_Data> data_set_;
  mat data_matrix_;//a data matrix store all data attribute
  Mat<size_t> data_set_neigbour_;//all neighbour index sorted by distance
  mat data_set_dis_;//sorted distance matrix
  std::vector<std::vector<t_S> > score_;
};

#endif // NNDM_H
