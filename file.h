#ifndef FILE_H
#define FILE_H
#include<fstream>
#include<iostream>

#include "data_struct.h"

class DataFile
{
 public:
    //构造函数
    DataFile(char* file_input,char* file_output);

    //析构函数
    ~DataFile();

 public:

    //设置输入数据的文件名
    bool SetFileInput(char* file_input);

    //设置输出数据的文件名
    bool SetFileOutput(char* file_output);

    //读取文件中的数据
    bool ReadInputFile(std::vector<t_Data>* data_set,int attribute_num);

    //将score 写入到输出文件中
    bool WriteScoreToFile(std::vector<t_Data>* data_set,
                          std::vector<t_AnomalyScore>* anomaly_score);

    //将聚类结果写到文件中
    bool WrithClusterData(std::vector<t_Cluster>*cluster_data_set,
                          std::vector<t_Data>*data_set,char*file_name);
    //将lof结果写到文件
    bool WriteLOFResult(std::vector<t_Data>* data_set,char* file_name);

protected:

private:
    char* file_input_;
    char* file_output_;

};
#endif // FILE_H
