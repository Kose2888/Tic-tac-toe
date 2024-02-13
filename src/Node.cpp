#include "Node.h"

Node::Node() {
  id = 0;
  parent = NULL;
}

Node::~Node() {
  for(int i = 0; i < children.size(); i++) {
    delete children[i];
  }
}

void Node::addChild(Node *child) {
  child->id = this->id + 1;
  child->s.setState(this->s.getlM(),this->s.getrM(), this->s.getlC(), this->s.getrC(), this->s.getBoat());
  child->parent = this;
  children.push_back(child);
}
