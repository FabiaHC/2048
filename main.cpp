#include <iostream>

#include <cstdlib>
#include <ctime>

#include "board.h"
#include "logic.h"

int main()
{
  srand(time(NULL));
  bool gameRunning{true};
  int board[5][5]{0};
  int score{0};
  /*while (!gameRunning)
  {

  }*/
  for (int i{0}; i < 20; i++)
  {
    std::cout << logic::random(0,10) << std::endl;
  }
  return 0;
}
