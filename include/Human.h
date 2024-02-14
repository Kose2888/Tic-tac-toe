#ifndef HUMAN_H
#define HUMAN_H

#include "Player.h"

class Human : public Player {
  private:

  public:
    Human();

    ~Human();

    int determineMove();

};

#endif
