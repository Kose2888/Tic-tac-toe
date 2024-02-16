#include <iostream>

#include "gtest/gtest.h"
#include "Node.h"
#include "Player.h"
#include "Human.h"
#include "AI.h"
#include "Grid.h"

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

TEST_F(Test, nextMoveTest) {
  root->nextXMoves();

  for(int i = 0; i <= root->children.size() - 1; i++) {
    root->children[i]->g.displayGrid();
  }
}

/*------------Player Tests-----------------*/

TEST_F(Test, humanConstructorTest) {
  Human *h = new Human;

  EXPECT_EQ(h->getX(), false);
  EXPECT_EQ(h->getO(), true);\
  //EXPECT_EQ(h->determineMove(), 10);

  delete h;
}


/*------------Grid Tests-----------------*/

TEST_F(Test, gridConstructorTest) {
  Grid *g = new Grid;

  for(int i = 0; i <= 8; i++) {
    EXPECT_EQ(g->getGrid()[i], ' ');
  }

  g->displayGrid();

  delete g;
}

TEST_F(Test, gridSetSquareTest) {
  Grid *g = new Grid;

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

TEST_F(Test, gridCheckWinTest) {
  Grid *g = new Grid;

  // Check Vertical X
  g->setSquare(2, 'X');
  g->setSquare(5, 'X');
  g->setSquare(8, 'X');

  g->displayGrid();

  EXPECT_EQ(g->checkWin(), 1);
  g->resetGrid();

  // Check Horizontal X
  g->setSquare(6, 'X');
  g->setSquare(7, 'X');
  g->setSquare(8, 'X');

  g->displayGrid();

  EXPECT_EQ(g->checkWin(), 1);
  g->resetGrid();

  // Check Diagonal X
  g->setSquare(6, 'X');
  g->setSquare(4, 'X');
  g->setSquare(2, 'X');

  g->displayGrid();

  EXPECT_EQ(g->checkWin(), 1);
  g->resetGrid();


  // Check Vertical O
  g->setSquare(0, 'O');
  g->setSquare(3, 'O');
  g->setSquare(6, 'O');

  g->displayGrid();

  EXPECT_EQ(g->checkWin(), -1);
  g->resetGrid();

  // Check Horizontal O
  g->setSquare(0, 'O');
  g->setSquare(1, 'O');
  g->setSquare(2, 'O');

  g->displayGrid();

  EXPECT_EQ(g->checkWin(), -1);
  g->resetGrid();

  // Check Diagonal O
  g->setSquare(0, 'O');
  g->setSquare(4, 'O');
  g->setSquare(8, 'O');

  g->displayGrid();

  EXPECT_EQ(g->checkWin(), -1);

  // Check tie
  g->setSquare(0, 'O');
  g->setSquare(1, 'X');
  g->setSquare(2, 'X');
  g->setSquare(3, 'X');
  g->setSquare(4, 'O');
  g->setSquare(5, 'O');
  g->setSquare(6, 'X');
  g->setSquare(7, 'O');
  g->setSquare(8, 'X');

  g->displayGrid();

  EXPECT_EQ(g->checkWin(), 0);
  g->resetGrid();

  // Check no win and no tie
  g->setSquare(0, 'O');
  g->setSquare(1, 'X');
  g->setSquare(2, 'X');
  g->setSquare(3, 'X');

  g->displayGrid();

  EXPECT_EQ(g->checkWin(), 2);

  delete g;
}

// Make a function for turns
// Make a function for adding children nodes based on all possible moves for that players turn
