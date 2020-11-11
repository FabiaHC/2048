#ifndef LOGIC_H
#define LOGIC_H

#include <vector>

namespace logic
{
  int random(int min, int max);

  enum direction
  {
    right = 0,
    left = 1,
    down = 2,
    up = 3
  };

  void scooch(std::vector< std::vector<int> > &board, direction dir);

  void rotateRight(std::vector< std::vector<int> > &board);

  void flip(std::vector< std::vector<int> > &board);
}

#endif
