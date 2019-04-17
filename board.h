#ifndef BOARD_H
#define BOARD_H

#include <vector>

namespace board
{
  std::vector <std::vector<int> > create();

  void display(std::vector <std::vector<int> > board);

  std::vector<std::vector<int> > getAvilablePositions(std::vector <std::vector<int> > board);

  void integrate(std::vector <std::vector<int> > &board, int number);

  bool exists(std::vector <std::vector<int> > &board, int numberTarget);
}

#endif
