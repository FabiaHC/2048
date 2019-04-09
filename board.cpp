#include <iostream>
#include <vector>

#include "board.h"

std::vector <std::vector<int> > board::create()
{
  std::vector <std::vector<int> > board;
  for (int y{0}; y < 5; y++)
  {
    board.push_back(std::vector<int>{0,0,0,0,0});
  }
  return board;
}

void board::display(std::vector <std::vector<int> > board)
{
  for (int y{0}; y < board.size(); y++)
  {
    for (int x{0}; x < board.at(y).size(); x++)
    {
      std::cout << board[y][x];
    }
    std::cout << std::endl;
  }
}

std::vector<std::vector<int> > board::getAvilablePositions(std::vector <std::vector<int> > board)
{
  std::vector<std::vector<int> > positions;
  for (int y{0}; y < 5; y++)
  {
    for (int x{0}; x < 5; x++)
    {
      if (board[y][x] == 0)
      {
        positions.push_back(std::vector<int>{y, x});
      }
    }
  }
  return positions;
}
