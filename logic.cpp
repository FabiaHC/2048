#include <cstdlib>

#include "logic.h"

int logic::random(int min, int max)
{
  if (min == max)
  {
    return min;
  }
  return rand()%max+min;
}
