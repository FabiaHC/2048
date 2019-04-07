#include <cstdlib>

#include "logic.h"

int logic::random(int min, int max)
{
  return rand()%max+min;
}
