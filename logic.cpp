#include <vector>
#include <iostream>

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
}
