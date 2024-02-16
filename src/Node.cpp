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

  if(min == true) {
    child->min = false;
    child->max = true;
  }

  if(max == true) {
    child->max = false;
    child->min = true;
  }

  if(child->g.checkWin() != 2) {
    child->max = false;
    child->min = false;
    child->terminal = true;
  }

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

void Node::nextOMoves() {
  for (int i = 0; i <= 8; i++) {
    if(g.getGrid()[i] == ' ') {
      Node *child = new Node(g);
      child->g.setSquare(i, 'O');
      addChild(child);
    }
  }
}
