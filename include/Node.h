#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>


class Node {
  private:

  public:

    int id;
    Node *parent;
    std::vector<Node*> children;

    Node();

    ~Node();

    void addChild(Node *);

};

#endif
