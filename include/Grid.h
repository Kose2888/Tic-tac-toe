#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>


class Grid {
  private:
    std::vector<char> grid;

  public:
    Grid();

    ~Grid();

    std::vector<char> getGrid() {return grid;}

    void setSquare(int, char);

    char getSquare(int n) const {return grid[n];}

    void displayGrid();

    void resetGrid();

    // -1 = O wins, 0 = tie, 1 = X wins, 2 = game not finished
    int checkWin();

};


#endif
