#include <vector>

#ifndef BOARD_H
#define BOARD_H

namespace board
{
  std::vector <std::vector<int> > create();

  void display(std::vector <std::vector<int> > board);

  std::vector<std::vector<int> > getAvilablePositions(std::vector <std::vector<int> > board);
}

#endif
