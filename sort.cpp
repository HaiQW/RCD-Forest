#include "sort.h"

Sort::Sort()
{
}

//sort the anomaly set
void Sort::SortAnomalyScore(std::vector<t_AnomalyScore>& score_set)
{
  std::sort(score_set.begin(),score_set.end(),CmpAnomalyScore);
}
