#include <iostream>

#include "Game.h"

int main(int argc, char *argv []) {

  char answer;
  int human = 0, ai = 0;
  do{

  Game *game = new Game;

  game->startGame(human, ai);

  delete game;

  std::cout << "Human Score: " << human << std::endl;
  std::cout << "AI Score: " << ai << std::endl;

  std::cout << "Would you like to play again(Y/N): ";
  std::cin >> answer;

  }while(answer == 'Y' || answer == 'y');

}
