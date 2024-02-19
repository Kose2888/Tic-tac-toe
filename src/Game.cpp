#include "Game.h"

Game::Game() {
  ai = new AI;
  human = new Human;
  node = new Node;
}

Game::~Game() {
  delete ai;
  delete human;
  delete node;
}

void Game::displayRules() {
  std::cout << "Tic-Tac-Toe\n" << std::endl;

  std::cout << "Rules: The game is played on a grid that's 3 squares by 3 squares. You can choose to be X or O (X goes first). Players take turns putting their marks in empty squares. The first player to get 3 of her marks in a row (up, down, across, or diagonally) is the winner.\n" << std::endl;

  std::cout << "Controls: 0-8 on the keyboard corresponds to " << std::endl;
  std::cout << "0" << " | " << "1" << " | " << "2"
    << "\n---------\n"
    << "3" << " | " << "4" << " | " << "5"
    << "\n---------\n"
    << "6" << " | " << "7" << " | " << "8"
    << "\n" << std::endl;
}

void Game::chooseSide() {
  char choice;
  bool invalid = false;

  do{

  std::cout << "Choose your side:\n" << "1) X (Goes first)\n"
    << "2) O\n" << "Enter: ";

    std::cin >> choice;

    switch(choice) {
      case '1':
        human->setIsX(true);
        ai->setIsO(true);
        break;
      case '2':
        human->setIsO(true);
        ai->setIsX(true);
        break;
      default:
        invalid = true;
    }

  }while(invalid);

}

void Game::startGame() {

  displayRules();
  chooseSide();

  bool gameOver = false;

  do{

    if(human->getX() == true) {
      bool illegalMove;
      do{
        illegalMove = false;
        int hmove = human->determineMove();
        if(grid.getGrid()[hmove] == ' ') {
          grid.setSquare(hmove, 'X');
          grid.displayGrid();
        }
        else{
          illegalMove = true;
          std::cout << "Square already taken!" << std::endl;
        }

      }while(illegalMove);

      if(grid.checkWin() != 2) {
        gameOver = true;
        break;
      }

      // AI Turn
      std::cout << "AI move:" << std::endl;
      std::vector<Node*> path;
      node->min = true;
      node->g = grid;
      node->parent = NULL;

      std::cout << "Node:\n";
      node->g.displayGrid();

      bool invalid = true;
      int amove;
      amove = ai->determineMove(node, path, -1000, 1000, node->id);
      std::cout << "amove = " << amove << std::endl;

      if(grid.getSquare(amove) == 'X' || grid.getSquare(amove) == 'O' ) {
        std::cout << "ENTER SHITTY FIX" << std::endl;
        node->nextXMoves();

        for(int i = 0; i < node->children.size(); i++) {
          if(node->children[i]->g.checkWin() == 1) {
            for(int j = 0; j < 9; j++) {
              if(grid.getSquare(j) != node->children[i]->g.getSquare(j) ){
                std::cout << "amove = " << amove << std::endl;
                amove = j;
                break;
              }
            }
          }
        }

      }
      if (grid.getSquare(amove) != ' ') {
        for(int i = 0; i < 9; i++) {
          if(grid.getSquare(i) == ' ') {
            amove = i;
            break;
          }
        }
      }

      grid.setSquare(amove, 'O');
      grid.displayGrid();
      path.clear();
    }
    else if(human->getX() == false) {
      // AI Turn
      std::cout << "AI move:" << std::endl;
      std::vector<Node*> path;
      node->max = true;
      node->g = grid;
      node->parent = NULL;

      std::cout << "Node:\n";
      node->g.displayGrid();

      bool invalid = true;
      int amove;
      amove = ai->determineMove(node, path, -1000, 1000, node->id);
      std::cout << "amove = " << amove << std::endl;

      if(grid.getSquare(amove) == 'X' || grid.getSquare(amove) == 'O' ) {
        std::cout << "ENTER SHITTY FIX" << std::endl;
        node->nextOMoves();

        for(int i = 0; i < node->children.size(); i++) {
          if(node->children[i]->g.checkWin() == -1) {
            for(int j = 0; j < 9; j++) {
              if(grid.getSquare(j) != node->children[i]->g.getSquare(j) ){
                std::cout << "amove = " << amove << std::endl;
                amove = j;
                break;
              }
            }
          }
        }

      }
      if (grid.getSquare(amove) != ' ') {
        std::cout << "enter shitty fix 2" << std::endl;
        for(int i = 0; i < 9; i++) {
          if(grid.getSquare(i) == ' ') {
            amove = i;
            break;
          }
        }
      }

      grid.setSquare(amove, 'X');
      grid.displayGrid();
      path.clear();


      if(grid.checkWin() != 2) {
        gameOver = true;
        break;
      }


      bool illegalMove;
      do{
        illegalMove = false;
        int hmove = human->determineMove();
        if(grid.getGrid()[hmove] == ' ') {
          grid.setSquare(hmove, 'O');
          grid.displayGrid();
        }
        else{
          illegalMove = true;
          std::cout << "Square already taken!" << std::endl;
        }

      }while(illegalMove);
    }
    else {
      std::cout << "Error in determining move" << std::endl;
    }

    if(grid.checkWin() != 2)
      gameOver = true;

  }while(!gameOver);

}
