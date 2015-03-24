#ifndef PRINTHELP_H
#define PRINTHELP_H

#include <stdlib.h>
#include <vector>
#include <iostream>

#include "data_struct.h"
class PrintHelp
{
public:
  PrintHelp();
  static void PrintAnomalyScore(std::vector<t_AnomalyScore> score_set);
};

#endif // PRINTHELP_H
