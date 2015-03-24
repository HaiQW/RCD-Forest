#include "printhelp.h"

PrintHelp::PrintHelp()
{
}

void PrintHelp::PrintAnomalyScore(std::vector<t_AnomalyScore> score_set)
{
  int data_size = score_set.size();
  //print score
  for ( unsigned i = 0 ; i < data_size ; i++ )
    {
      t_AnomalyScore score_temp = score_set[i];
      std::cout<<"index:"<<i<<"score:"<<score_temp.score_
              <<"class_label:"<<score_temp.class_label_
             <<std::endl;
    }
}
