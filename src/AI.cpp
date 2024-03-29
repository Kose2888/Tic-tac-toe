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

int AI::minmax(Node *node, std::vector<Node*> &path, int alpha, int beta, int id) {
  //node->g.displayGrid();
  if(node->terminal == true) {
    if(node->id > id){
      path.push_back(node);
    }
    return node->g.checkWin();
  }

  else if(node->max == true){
    node->nextXMoves();
    int b = MIN;

    for(int i = 0; i < node->children.size(); i++) {
      int val = minmax(node->children[i], path, alpha, beta, id);
      b = std::max(b, val);
      alpha = std::max(alpha, b);

      if(beta <= alpha) {
        break;
      }
    }
    return b;
  }
  else {
    node->nextOMoves();
    int b = MAX;

    for(int i = 0; i < node->children.size(); i++) {
      int val = minmax(node->children[i], path, alpha, beta, id);
      b = std::min(b, val);
      beta = std::min(beta, b);

      if(beta <= alpha) {
        break;
      }
    }
    return b;
  }
}

Node * AI::bestBranch(Node *node) {
  if(node->id == 1)
    return node;

  return bestBranch(node->parent);
}

Node * AI::bestXTerminal(std::vector<Node *> path) {
  Node *best = path[0];
  for(int i = 0; i < path.size() -1; i++) {
    if( (path[i+1]->id < best->id) && path[i+1]->g.checkWin() == 1)
      best = path[i+1];
  }
  return best;
}

Node * AI::bestOTerminal(std::vector<Node *> path) {
  Node *best = path[0];
  for(int i = 0; i < path.size() -1; i++) {
    if( (path[i+1]->id < best->id) && path[i+1]->g.checkWin() == -1)
      best = path[i+1];
  }
  return best;
}

int AI::determineMove(Node *node, std::vector<Node*> &path, int alpha, int beta, int id) {
  int minimax = minmax(node, path, alpha, beta, id);

  bool limit = false;
  int i = 0;
  /*
  do{
    for(int j = 0; j < 9; j++) {
      if( (node->g.getSquare(j) == 'X' && path[i]->g.getSquare(j) != 'X') || ( node->g.getSquare(j) == 'O' && path[i]->g.getSquare(j) != 'O') )
        //std::cout << "Error: Bad path node" << std::endl;
        break;
    }
    if(i == path.size() - 1)
      limit = true;
    i++;

  }while(!limit);
*/

  if(this->getX() == true){
    Node *best;
    best = bestXTerminal(path);

    for(int i = 0; i < 9; i++) {
      if(best->g.getSquare(i) != best->parent->g.getSquare(i))
        return i;
    }
  }
  if(this->getO() == true){
    Node *best;
    best = bestOTerminal(path);

    for(int i = 0; i < 9; i++) {
      if(best->g.getSquare(i) != best->parent->g.getSquare(i))
        return i;
    }
  }
  std::cout << "Error: determinMove" << std::endl;
  return 200;
}
