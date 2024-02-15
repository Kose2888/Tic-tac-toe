#include <iostream>

#include "gtest/gtest.h"
#include "Node.h"
#include "Player.h"
#include "Human.h"
#include "AI.h"
#include "Game.h"

class Test : public testing::Test {
  protected:
    Node *root;

    void SetUp() override {
      root = new Node;
    }

    void TearDown() override {
      delete root;
    }
};


/*------------Node Tests-----------------*/

TEST_F(Test, nodeConstructorTest) {
  EXPECT_EQ(root->id, 0);
  EXPECT_EQ(root->children.size(), 0);
  EXPECT_FALSE(root->min);
  EXPECT_FALSE(root->max);
  EXPECT_FALSE(root->terminal);
}

TEST_F(Test, nodeSetFuncTest) {
  root->setMin(true);
  root->setMax(true);
  root->setTerminal(true);

  EXPECT_TRUE(root->getMin());
  EXPECT_TRUE(root->getMax());
  EXPECT_TRUE(root->getTerminal());
}

TEST_F(Test, addChildNodeTest) {
  Node *child = new Node;

  root->addChild(child);

  EXPECT_EQ(root->id, 0);
  EXPECT_EQ(root->children.size(), 1);

  EXPECT_EQ(child->id, 1);
  EXPECT_EQ(child->parent, root);

  Node *child2 = new Node;

  child->addChild(child2);

  EXPECT_EQ(root->children.size(), 1);
  EXPECT_EQ(child2->id, 2);
  EXPECT_EQ(child2->parent, child);
}


/*------------Player Tests-----------------*/

TEST_F(Test, humanConstructorTest) {
  Human *h = new Human;

  EXPECT_EQ(h->getX(), false);
  EXPECT_EQ(h->getO(), true);\
  //EXPECT_EQ(h->determineMove(), 10);

  delete h;
}


/*------------Game Tests-----------------*/

TEST_F(Test, gameConstructorTest) {
  Game *g = new Game;

  for(int i = 0; i <= 8; i++) {
    EXPECT_EQ(g->getGrid()[i], ' ');
  }

  g->displayGrid();

  delete g;
}

TEST_F(Test, gameSetSquareTest) {
  Game *g = new Game;

  for(int i = 0; i <= 8; i++) {
    g->setSquare(i, 'X');
    EXPECT_EQ(g->getGrid()[i], 'X');
  }
  g->displayGrid();

  g->resetGrid();

  for(int i = 0; i <= 8; i++) {
    g->setSquare(i, 'O');
    EXPECT_EQ(g->getSquare(i), 'O');
  }
  g->displayGrid();

  delete g;
}

// Test checkwin
// Make a function for turns
// Make a function for adding children nodes based on all possible moves for that players turn
