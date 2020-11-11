#include <iostream>
#include <vector>

#include "board.h"
#include "logic.h"

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

void board::integrate(std::vector <std::vector<int> > &board, int number)
{
  std::vector<std::vector<int> > positions = board::getAvilablePositions(board);
  int sparePosition = logic::random(0, positions.size()-1);
  int y = positions.at(sparePosition).at(0);
  int x = positions.at(sparePosition).at(1);
  board.at(y).at(x) = 2;
}

bool board::exists(std::vector <std::vector<int> > &board, int numberTarget)
{
  for (int y{0}; y < board.size(); y++)
  {
    for (int x{0}; x < board.size(); x++)
    {
      if (numberTarget == board.at(y).at(x))
      {
        return true;
      }
    }
  }
  return false;
}
