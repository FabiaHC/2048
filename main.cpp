#include <iostream>
#include <string>

#include <cstdlib>
#include <ctime>

#include "board.h"
#include "logic.h"

int main()
{
  srand(time(NULL));
  bool gameRunning{true};
  std::vector <std::vector<int> > board = board::create();
  int score{0};
  std::string command;
  while (gameRunning)
  {
    std::cout << "=====" << std::endl;
    board::integrate(board, 2);
    board::display(board);
    std::cin >> command;

    if (command == "quit")
    {
      gameRunning = false;
      std::cout << "Quiting..." << std::endl;
    }

    else if (command == "right")
    {
      logic::scooch(board, logic::direction::right);
    }

    else if (command == "left")
    {
      logic::scooch(board, logic::direction::left);
    }

    else if (board::getAvilablePositions(board).size() == 0)
    {
      gameRunning = false;
      std::cout << "You Lose!" << std::endl;
    }
  }
  return 0;
}
