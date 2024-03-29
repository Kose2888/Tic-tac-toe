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

    int minmax(Node *node, std::vector<Node*> &path, int alpha, int beta, int id);

    Node * bestBranch(Node *);

    Node * bestXTerminal(std::vector<Node*>);

    Node * bestOTerminal(std::vector<Node*>);

    int determineMove(Node *node, std::vector<Node*> &path, int alpha, int beta, int id);

};

#endif
