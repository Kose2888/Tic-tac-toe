#include "Grid.h"

Grid::Grid() {
  for(int i = 0; i <= 8; i++) {
    grid.push_back(' ');
  }
}

Grid::~Grid() {
}

void Grid::setSquare(int n, char c) {
  if(c == 'X' || c == 'O' || n >= 0 || n <= 8) {
    grid[n] = c;
  }
  else
    std::cout << "Error: Invalid position or not X or O" << std::endl;
}

void Grid::displayGrid() {
  std::cout << grid[0] << " | " << grid[1] << " | " << grid[2]
    << "\n---------\n"
    << grid[3] << " | " << grid[4] << " | " << grid[5]
    << "\n---------\n"
    << grid[6] << " | " << grid[7] << " | " << grid[8]
    << "\n" << std::endl;
}

void Grid::resetGrid() {
  for(int i = 0; i <= 8; i++)
    grid[i] = ' ';
}

int Grid::checkWin() {
  // Check for O horizontal win
  for(int i = 0; i <= 7; i++) {
    if(grid[i] == 'O' && grid[i+1] == 'O' && grid[i+2] == 'O')
      return -1;
      i += 2;
  }

  // Check for O vertical win
  for (int i = 0; i <= 2; i++) {
    if(grid[i] == 'O' && grid[i+3] == 'O' && grid[i+6] == 'O')
      return -1;
  }

  // Check for O diagonal win
  if( (grid[0] == 'O' && grid[4] == 'O' && grid[8] == 'O')
      || (grid[6] == 'O' && grid[4] == 'O' && grid[2] == 'O'))
    return -1;

  // Check for X horizontal win
  for(int i = 0; i <= 7; i++) {
    if(grid[i] == 'X' && grid[i+1] == 'X' && grid[i+2] == 'X')
      return 1;
      i += 2;
  }

  // Check for X vertical win
  for (int i = 0; i <= 2; i++) {
    if(grid[i] == 'X' && grid[i+3] == 'X' && grid[i+6] == 'X')
      return 1;
  }

  // Check for X diagonal win
  if( (grid[0] == 'X' && grid[4] == 'X' && grid[8] == 'X')
      || (grid[6] == 'X' && grid[4] == 'X' && grid[2] == 'X'))
    return 1;

  // Check if there are any empty spaces
  for(int i = 0; i <= 8; i++) {
    if(grid[i] == ' ') {
      std::cout << "CheckWin: Board is not filled yet" << std::endl;
      return 2;
    }
  }
  // If no empty spaces or a win, then tie
  return 0;
}
