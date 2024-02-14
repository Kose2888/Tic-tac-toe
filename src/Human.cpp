#include <iostream>
#include <string>

#include "Human.h"

Human::Human() {
}

Human::~Human() {
}

int Human::determineMove() {
  bool invalid;
  int ans;
  do {
    invalid = false;
    std::string input;

    std::cout << "Enter Move: ";
    std::cin >> input;
    std::cout << std::endl;

    //going to have to check if input is valid on the grid

    if(input.size() == 1) {

      switch(input[0]) {
        case '0':
          ans = 0;
          break;
        case '1':
          ans = 1;
          break;
        case '2':
          ans = 2;
          break;
        case '3':
          ans = 3;
          break;
        case '4':
          ans = 4;
          break;
        case '5':
          ans = 5;
          break;
        case '6':
          ans = 6;
          break;
        case '7':
          ans = 7;
          break;
        case '8':
          ans = 8;
          break;
        default:
          std::cout << "Error: Invalid Input" << std::endl;
          ans = -1;
          invalid = true;
          break;
      }
    }
    else {
      std::cout << "Error: Invalid Input" << std::endl;
      invalid = true;
    }
  }while(invalid);
  return ans;
}
