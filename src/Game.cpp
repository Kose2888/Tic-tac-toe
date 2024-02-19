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

      std::cout << "AI move:" << std::endl;
      std::vector<Node*> path;
      node->min = true;
      node->g = grid;

      std::cout << "Node:\n";
      node->g.displayGrid();

      int amove = ai->determineMove(node, path, -1000, 1000);
      std::cout << "amove = " << amove << std::endl;

      /*
      std::cout << "PATHS" << std::endl;
      for(int i = 0; i < path.size(); i++) {
        path[i]->g.displayGrid();
      }
      */

      grid.setSquare(amove, 'O');
      grid.displayGrid();
      path.clear();
    }
    else if(human->getX() == false) {
      std::cout << "AI move:" << std::endl;
      std::vector<Node*> path;
      node->max = true;
      node->g = grid;
      grid.setSquare(ai->determineMove(node, path, -1000, 1000), 'X');
      grid.displayGrid();
      path.clear();


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
