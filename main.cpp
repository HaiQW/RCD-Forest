/*
 *main function
 **/

#include <mlpack/core.hpp>
#include <mlpack/methods/kmeans/kmeans.hpp>
#include <vector>

#include "file.h"
#include "itree.h"
#include "utility.h"
#include "iforest.h"
#include "sort.h"
#include "printhelp.h"
#include "nndm.h"

using namespace mlpack::kmeans;
using namespace mlpack::metric; // ManhattanDistance
using namespace mlpack;

int main()
{
    std::vector<t_Data> data_test;
    std::vector<t_Data> candidate_set;
    std::vector<t_Range> range_test;
    std::vector<t_AnomalyScore> score_test;
    t_Configure configure_test;
    DataProcess* process_test;
    IForest* iforest_test;
    NNDM* nndm_test;

    char*config_file = "satellite/satellite_config.txt";
    char*test_output_file = "satellite/satellite.txt";

    //load configure file
    configure_test = SetConfiguraion(config_file);
    DataFile file_test(configure_test.data_file_,test_output_file);
    file_test.ReadInputFile(&data_test,configure_test.dimension_size_);

    //set dimension ranges
    for( int i = 0 ; i < configure_test.dimension_size_ ; i++){
        t_Range range;
        range.left_margin_ = -0.1;
        range.right_margin_ = 1.1;
        range_test.push_back(range);
    }
    //dynamic allocate memory and construct objects

    //normalize data to(0,1)
    process_test = new DataProcess(data_test,range_test,configure_test.bin_width_,
                                   configure_test.dimension_size_);
    process_test->NormalizeData();
    iforest_test = new IForest(configure_test.tree_num_,
                               log(double(configure_test.sample_size_)),
                               configure_test.sample_size_,
                               process_test);
    iforest_test->BuidIforest();
    score_test = iforest_test->CalculateAllScore();

    //calculate candidate data
    Sort::SortAnomalyScore(score_test);
    PrintHelp::PrintAnomalyScore(score_test);
    SetCandidateDataSet(0.7,&data_test,&score_test,&candidate_set);
    //allocate memory for NNDM pointer
    nndm_test = new NNDM(candidate_set,
                         configure_test.p_set,
                         candidate_set.size(),
                         configure_test.class_num_,
                         configure_test.dimension_size_);
    nndm_test->CalculateClassNum();
    nndm_test->CalculateR();
    nndm_test->CalculateNN();
    nndm_test->DiscoverClass();
}
