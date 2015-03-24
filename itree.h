/*
 * iTree's Class header file and iTRee is the manily class of this
 * algorithm.ITree is like a random tree.
 */
#ifndef  ITREE_H
#define  ITREE_H

#include<vector>
#include<iostream>
#include<limits.h>
#include<exception>

#include"data_struct.h"
#include"float.h"
#include"dataprocess.h"

class iTree
{
public:
     iTree(DataProcess* data_procession,int height_max);
     ~iTree();

public:
    //构建一颗ITree
    void BuildITree();
    //构建一颗ITree
    void BuildITree(std::vector<t_Data>*data_set,
                     t_INode* root,
                     int current_height);

    //搜索ITree，返回一个score值
    double SearchInstance(t_Data data_point,
                          t_INode* root,
                          int height);
    //search every instance in the dataset
    std::vector<t_AnomalyScore> SearchAll();
    //计算AnomalyScore的值
    double CalculateAnomalyScore(int average_length,int n);


    //print itree without parameter
    void PrintITree();
    //打印ITree
    void PrintITree(t_INode* root);

    //获取ITree的root节点
    t_INode* GetRoot();

protected:

private:
    //iTree 的root节点
    t_INode* itree_root_ ;
    //绑定的数据处理类
    DataProcess* data_procession_;
    //iTree 的最大高度
    int height_max_;

};
#endif // ITREE_H
