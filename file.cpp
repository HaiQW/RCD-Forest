#include"file.h"
#include<stdlib.h>
//-----------------------------------------------------------------------------------
//DataFile构造函数
//-----------------------------------------------------------------------------------
DataFile::DataFile(char* file_input,char* file_output)
{
    file_input_ = file_input;
    file_output_ = file_output;
}

//-----------------------------------------------t------------------------------------
//DataFile析构函数
//-----------------------------------------------------------------------------------
DataFile::~DataFile()
{

}

//-----------------------------------------------------------------------------------
//设置输入文件
//-----------------------------------------------------------------------------------
bool DataFile::SetFileInput(char* file_input)
{
    if ( NULL == file_input ){
        std::cerr<<"error:could not set the source file name because of the NULL"
            <<"pointer!"<<std::endl;
        return false;
    }
    else
    {
        file_input_ = file_input;
        return true;
    }
}

//-----------------------------------------------------------------------------------
//设置输出文件
//-----------------------------------------------------------------------------------
bool DataFile::SetFileOutput(char* file_output)
{
    if(NULL == file_output)
    {
        std::cerr<<"error:could not set the output file name because of the NULL"
            <<" pointer!"<<std::endl;
        return false;
    }
    else
    {
        file_output_ = file_output;
        return true;
    }
}

//-----------------------------------------------------------------------------------
//读取输入文件
//-----------------------------------------------------------------------------------
bool DataFile::ReadInputFile(std::vector<t_Data>* data_set,int attribute_num)
{

    //关联一个读取文件流对象
    std::ifstream fin(file_input_);

    if(!fin.is_open())
    {
        std::cerr<<"error:could not open the file!"
            <<file_input_<<std::endl;
        exit(1);
    }
    //读取文件
    while(!fin.eof())
    {
        t_Data data_temp;
        double data_class;

        //读取一行数据
        for(int i = 0 ; i < attribute_num ; i++)
        {
            double attribute;
            fin>>attribute;
            data_temp.attribute_.push_back(attribute);
        }

        //读取每个实例所属的类别
        fin>>data_class;

        data_temp.data_class_ = data_class;
        data_temp.attribute_num_ = attribute_num;
        data_set->push_back(data_temp);
    }

    fin.close();
    return true;
}

//-----------------------------------------------------------------------------------
//anomalyscore写入文件
//-----------------------------------------------------------------------------------
bool DataFile::WriteScoreToFile(std::vector<t_Data>* data_set,
                                std::vector<t_AnomalyScore>* anomaly_score)
{

    std::fstream fout;
    fout.open(file_output_,std::ios::out);

    if(!fout.is_open())
    {
        std::cerr<<"could not create or open the file:"
            <<file_output_<<std::endl;
        exit(-1);
    }

    // 写入文件
    for( unsigned int i = 0 ; i < anomaly_score->size(); i++)
    {
        t_Data temp_data = data_set->at(anomaly_score->at(i).data_index_);
        fout<<"data_index:"<<i<<"  score:"<<anomaly_score->at(i).score_
            <<"  class_label:"<<temp_data.data_class_<<std::endl;
        //
        anomaly_score->at(i).class_label_ = temp_data.data_class_;
    }

    fout.close();
    return true;
}

//----------------------------------------------------------------------------------
//写聚类文件
//-----------------------------------------------------------------------------------
bool DataFile::WrithClusterData(std::vector<t_Cluster>*cluster_data_set,
                                std::vector<t_Data>*data_set,char*file_name)
{
    std::fstream fout;
    fout.open(file_name,std::ios::out);

    if(!fout.is_open())
    {
        std::cerr<<"could not create or open the file:"
            <<file_output_<<std::endl;
        exit(-1);
    }

    for(unsigned int i = 0 ; i < cluster_data_set->size() ;i++)
    {
        for( unsigned int j = 0 ; j < cluster_data_set->at(i).data_set_index.size();j++){
            int index = cluster_data_set->at(i).data_set_index.at(j);
            t_Data temp = data_set->at(index);
            fout<<"data_index:"<<i<<"  cluster_label:"<<i<<"  class_label:"
            <<temp.data_class_<<"  distance:"<<" "<<std::endl;
        }
    }
    fout.close();
    return true;
}


//-----------------------------------------------------------------------------------
//将LOF值写入文件
//-----------------------------------------------------------------------------------
bool DataFile::WriteLOFResult(std::vector<t_Data>* data_set,char* file_name)
{
    std::fstream fout;
    fout.open(file_name,std::ios::out);

    // 判断文件是否能打开
    if(!fout.is_open())
    {
        std::cerr<<"could not create or open the file:"
            <<file_output_<<std::endl;
        exit(-1);
    }

    for(unsigned int  i = 0 ; i < data_set->size() ;i++)
    {
        t_Data temp_data = data_set->at(i);
        fout<<"data_index:"<<i<<"  lof_value:"<<temp_data.lof_<<"  class_label:"
            <<temp_data.data_class_<<std::endl;
    }
    fout.close();
    return true;
}
