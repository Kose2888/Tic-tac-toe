#ifndef AI_H
#define AI_H

#include "Player.h"
#include "Node.h"
#include <bits/stdc++.h>

const int MAX = 1000;
const int MIN = -1000;

class AI : public Player {
  private:

  public:
    AI();

    ~AI();

    int buildTree(Node *, int v);

    int determineMove();

    int minmax(Node *node, std::vector<Node*> &path, int alpha, int beta);

    Node * bestBranch(Node *);

};

#endif
