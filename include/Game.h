#ifndef GAME_H
#define GAME_H

#include <iostream>

#include "Player.h"
#include "AI.h"
#include "Human.h"
#include "Node.h"
#include "Grid.h"


class Game {
  private:
    AI *ai;
    Human *human;
    Node *node;
    Grid grid;

  public:

    Game();

    ~Game();

    void displayRules();

    void chooseSide();

    void startGame(int &humanScore, int &aiScore);

};

#endif
