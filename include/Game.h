#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>

#include "Player.h"
#include "Human.h"
#include "AI.h"
#include "Node.h"


class Game {
  private:
    std::vector<char> grid;

  public:
    Game();

    ~Game();

    std::vector<char> getGrid() {return grid;}

    void setSquare(int, char);

    char getSquare(int n) const {return grid[n];}

    void displayGrid();

    void resetGrid();

    // -1 = O wins, 0 = tie, 1 = X wins, 2 = game not finished
    int checkWin();

};


#endif
