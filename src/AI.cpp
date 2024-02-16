#include "AI.h"

AI::AI() {
}

AI::~AI() {
}

int AI::buildTree(Node *node, int v) {
  node->g.displayGrid();
  std::cout << "V = " << v << std::endl;
  if(node->terminal == true) {// Leaf node
    std::cout << "Reached terminal node" << std::endl;
    return 1;
  }

  if(node->max == true) {
    node->nextXMoves();
    for(int i = 0; i <= node->children.size() - 1; i++) {
      std::cout << "Loop MAX" << std::endl;
      //node->children[i]->g.displayGrid();
        v += buildTree(node->children[i], v);
    }
  }
  if(node->min == true) {
    node->nextOMoves();
    for(int i = 0; i <= node->children.size() - 1; i++) {
      std::cout << "Loop MIN" << std::endl;
        v += buildTree(node->children[i], v);
    }
  }
  return v;
}

int AI::minmax(Node *node, int best, int alpha, int beta) {
  //node->g.displayGrid();
  if(node->terminal == true)
    return node->g.checkWin();

  if(node->max == true){
    node->nextXMoves();
    int b = MIN;

    for(int i = 0; i < node->children.size(); i++) {
      int val = minmax(node->children[i], best, alpha, beta);
      b = std::max(b, val);
      alpha = std::max(alpha, b);

      if(beta <= alpha)
          break;
    }
    return b;
  }
  else {
    node->nextOMoves();
    int b = MAX;

    for(int i = 0; i < node->children.size(); i++) {
      int val = minmax(node->children[i], best, alpha, beta);
      b = std::min(beta, val);
      beta = std::min(beta, best);

      if(beta <= alpha)
        break;
    }
    return b;
  }
}

int AI::determineMove() {
  return 0;
}
