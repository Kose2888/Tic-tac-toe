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
  root->max = true;
  EXPECT_EQ(root->max, true);

  root->g.setSquare(0, 'O');
  root->g.setSquare(4, 'O');
  root->g.setSquare(7, 'O');

  root->nextXMoves();

  for(int i = 0; i <= root->children.size() - 1; i++) {
    root->children[i]->g.displayGrid();
    EXPECT_EQ(root->children[i]->min, true);
    EXPECT_EQ(root->children[i]->max, false);
    EXPECT_EQ(root->children[i]->terminal, false);
  }

  std::cout << "Level 2" << std::endl;
  root->children[0]->nextXMoves();
  root->children[0]->children[0]->g.displayGrid();
  EXPECT_EQ(root->children[0]->children[0]->max, true);
  EXPECT_EQ(root->children[0]->children[0]->min, false);
  EXPECT_EQ(root->children[0]->children[0]->terminal, false);
}
/*
TEST_F(Test, buildTreeTest) {
  AI *ai = new AI;
  int value = 0;

  root->max = true;
  root->g.setSquare(0, 'X');
  root->g.setSquare(1, 'O');
  root->g.setSquare(2, 'X');
  root->g.setSquare(3, 'X');
  root->g.setSquare(4, 'X');

  std::cout << "Size: " << ai->buildTree(root, value) << std::endl;

  //for(int i = 0; i <= root->children.size() - 1; i++){
  //  root->children[i]->g.displayGrid();
  //}

  delete ai;
}
*/

TEST_F(Test, miniMaxTest) {
  AI *ai = new AI;
  ai->setIsX(true);
  std::vector<Node*> path;

  root->max = true;
  root->g.setSquare(2, 'O');
  root->g.setSquare(4, '0');
  root->g.setSquare(3, 'X');
  root->g.setSquare(5, 'X');

  std::cout << "AI next move index: " << ai->determineMove(root, path, -1000, 1000) << std::endl;

  /*
  std::cout << "Minimax: " << ai->minmax(root, path, -1000, 1000) << std::endl;

  std::cout << "Path size: " << path.size() << std::endl;
  for(int i = 0; i < path.size(); i++) {
    std::cout << "In for loop" << std::endl;
    std::cout << path[i]->id << std::endl;
    path[i]->g.displayGrid();
  }

  std::cout << "Last" << std::endl;
  path[path.size()-2]->g.displayGrid();

  std::cout << "BEST" << std::endl;
  ai->bestXTerminal(path)->g.displayGrid();

  */

  delete ai;
}

/*------------Player Tests-----------------*/

TEST_F(Test, humanConstructorTest) {
  Human *h = new Human;

  EXPECT_EQ(h->getX(), false);
  EXPECT_EQ(h->getO(), true);
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
