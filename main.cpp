#include "./Headers/headers.h"

int main() {
  
  int selection = -1;
  do {
    std::cout << TEXT_BRIGHT_CYAN << welcomeMessage << std::endl; 
  } while (selection != 0);

  return 0;
}