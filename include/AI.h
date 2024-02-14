#ifndef AI_H
#define AI_H

#include "Player.h"

class AI : public Player {
  private:

  public:
    AI();

    ~AI();

    int determineMove();

};

#endif
