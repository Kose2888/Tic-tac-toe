#include "Node.h"

Node::Node() {
  id = 0;
  min = false;
  max = false;
  terminal = false;

  parent = NULL;
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
