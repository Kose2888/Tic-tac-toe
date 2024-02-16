#include "Node.h"

Node::Node() {
  id = 0;
  min = false;
  max = false;
  terminal = false;

  parent = NULL;
}

Node::Node(Grid g2) {
  id = 0;
  min = false;
  max = false;
  terminal = false;

  parent = NULL;

  for(int i = 0; i <= 8; i++) {
    g.setSquare(i, g2.getSquare(i));
  }
}

Node::~Node() {
  for(int i = 0; i < children.size(); i++) {
    delete children[i];
  }
}

void Node::addChild(Node *child) {
  child->id = this->id + 1;
  child->parent = this;
  children.push_back(child);
}

void Node::setMin(bool b) {
   min = b;
}

void Node::setMax(bool b) {
   max = b;
}

void Node::setTerminal(bool b) {
   terminal = b;
}

void Node::nextXMoves() {
  for (int i = 0; i <= 8; i++) {
    if(g.getGrid()[i] == ' ') {
      Node *child = new Node(g);
      child->g.setSquare(i, 'X');
      addChild(child);
    }
  }
}
