#include <vector>
#include <iostream>

#include <cstdlib>

#include "logic.h"
#include "board.h"

int logic::random(int min, int max)
{
  if (min == max)
  {
    return min;
  }
  return rand()%max+min;
}

void logic::scooch(std::vector< std::vector<int> > &board, logic::direction dir)
{
  if (dir == logic::direction::right)
  {
    for (int y{0}; y < board.size(); y++)
    {
      for (int x = board.at(y).size()-2; x >= 0; x--)
      {
        if (board.at(y).at(x) == 0)
        {
          continue;
        }

        else
        {
          for (int index = x+1; index < board.at(y).size(); index++)
          {
            if (index == board.at(y).size()-1 && board.at(y).at(index) == 0)
            {
              board.at(y).at(index) = board.at(y).at(x);
              board.at(y).at(x) = 0;
            }

            else if (board.at(y).at(index) == board.at(y).at(x))
            {
              board.at(y).at(index) *= 2;
              board.at(y).at(x) = 0;
              break;
            }

            else if (board.at(y).at(index) != 0)
            {
              int temp = board.at(y).at(x);
              board.at(y).at(x) = 0;
              board.at(y).at(index-1) = temp;
              break;
            }
          }
        }
      }
    }
  }

  else if (dir == logic::direction::left)
  {
    logic::flip(board);
    logic::scooch(board, logic::direction::right);
    logic::flip(board);
  }

  else if (dir == logic::direction::down)
  {
    logic::rotateRight(board);
    logic::scooch(board, logic::direction::right);
    for (int i{0}; i < 3; i++)
    {
      logic::rotateRight(board);
    }
  }

  else if (dir == logic::direction::up)
  {
    for (int i{0}; i < 3; i++)
    {
      logic::rotateRight(board);
    }
    logic::scooch(board, logic::direction::left);
    logic::rotateRight(board);
  }
}

void logic::rotateRight(std::vector< std::vector<int> > &board)
{
  std::vector <std::vector<int> > fakeBoard = board::create();
  for (int x{0}; x < board.size(); x++)
  {
    for (int y{0}; y < board.size(); y++)
    {
      fakeBoard.at(y).at(x) = board.at(x).at(y);
    }
  }
  board = fakeBoard;
}

/* For reference for turning it right:
1 2 3 //for x for y
10 20 30
100 200 300

1 10 100
2 20 200
3 30 300
*/

void logic::flip(std::vector< std::vector<int> > &board)
{
  int middleIndex = board.size()/2;
  if (board.size() % 2 == 1)
  {
    for (int y{0}; y < board.size(); y++)
    {
      for (int offset{0}; offset != middleIndex; offset++)
      {
        int temp = board.at(y).at(offset);
        board.at(y).at(offset) = board.at(y).at(board.size()-1-offset);
        board.at(y).at(board.size()-1-offset) = temp;
      }
    }
  }

  else if (board.size() & 0 == 0)
  {
    for (int y{0}; y < board.size(); y++)
    {
      for (int offset{0}; offset < board.size()/2; y++)
      {
        int temp = board.at(y).at(offset);
        board.at(y).at(offset) = board.at(y).at(board.size()-1-offset);
        board.at(y).at(board.size()-1-offset) = temp;
      }
    }
  }
}
