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
  int sparePosition;
  int x;
  int y;
  std::string command;
  while (gameRunning)
  {
    std::vector<std::vector<int> > positions = board::getAvilablePositions(board);
    sparePosition = logic::random(0, positions.size()-1);
    y = positions.at(sparePosition).at(0);
    x = positions.at(sparePosition).at(1);
    board.at(y).at(x) = 2;
    board::display(board);
    std::cin >> command;

    if (command == "quit")
    {
      gameRunning = false;
      std::cout << "Quiting..." << std::endl;
    }
  }
  return 0;
}
