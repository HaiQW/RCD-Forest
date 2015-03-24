#ifndef SORT_H
#define SORT_H

#include <algorithm>
#include <stdlib.h>

#include "data_struct.h"
#include "utility.h"

class Sort
{
public:
  Sort();
  static void SortAnomalyScore(std::vector<t_AnomalyScore>& score_set);
};

#endif // SORT_H
