#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>


class Node {
  private:

  public:

    int id;
    bool min;
    bool max;
    bool terminal;

    Node *parent;
    std::vector<Node*> children;

    Node();

    ~Node();

    void addChild(Node *);

    void setMin(bool);

    void setMax(bool);

    void setTerminal(bool);

    bool getMin() const {return min;}

    bool getMax() const {return max;}

    bool getTerminal() const {return terminal;}
};

#endif
