#include <iostream>

#include "board.h"

void board::display(int board[5][5])
{
  for (int y{0}; y < 5; y++)
  {
    for (int x{0}; x < 5; x++)
    {
      std::cout << board[y][x];
    }
    std::cout << std::endl;
  }
}
