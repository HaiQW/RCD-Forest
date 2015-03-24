#ifndef IFOREST_H
#define IFOREST_H

#include"itree.h"

class IForest {
public:
    IForest(int itrees_num,int itree_height,
            int sample_num,DataProcess* data_procession);
    ~IForest();

public:
    //构建Iforest
    void BuidIforest();
    //计算搜索分数
    double CalculateScore(t_Data data_point);
    //calculate all average anomaly search score
    std::vector<t_AnomalyScore> CalculateAllScore();

protected:

private:
    int itrees_num_;
    int sample_num_;
    int data_num_;
    std::vector<iTree*> itrees_set_;
    DataProcess* data_procession_;
};

#endif // IFOREST_H
