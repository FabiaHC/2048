#include <iostream>
#include <vector>

#include "board.h"
#include "logic.h"

int digitCount(int num) //returns the number of digits in the integer (base 10)
{
	int count = ( (num == 0) ? 1 : 0);
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return count;
}

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
	int number{0}; //number of current board cell
	int numberWidth; //number of digits of number
	int maxNumberWidth{5}; //width of the total size of the cell to be printed (4 characters as it goes up to 2048 (+1 for a space))
	int spaces; //number of extra spaces to keep board formatted when printed
	std::string extraSpaces;
  for (int y{0}; y < board.size(); y++)
  {
    for (int x{0}; x < board.at(y).size(); x++)
    {
			extraSpaces = "";
			number = board[y][x];
			numberWidth = digitCount(number);
			spaces = maxNumberWidth-numberWidth;
			for (int i{0}; i < spaces; i++)
			{
				extraSpaces += " ";
			}
			std::cout << number << extraSpaces;
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
