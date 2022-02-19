#include "./Headers/headers.h"

char getch();

int main() {
  
  int selection = -1;
  string choiceString;
  do {
    cout << TEXT_BRIGHT_CYAN << welcomeMessage << endl; 
    cout << selectGameMode << endl;
    cout << singlePlayerGame << endl;
    cout << aiOnlyGame << endl;
    cout << singlePlayerSalvo << endl;
    cout << multiPlayerSalvo << endl;
    cout << aiOnlySalvo << endl;
    cout << singlePlayerMines << endl;
    cout << multiPlayerMines << endl;
    cout << aiOnlyMines << endl;
    cout << endl;


    char deez = getch();
    string nuts;
    nuts.push_back(deez);
    selection = stoi(nuts); 

    Game newGame(selection);
    
    

  } while (selection != 0);

  return 0;
}

char getch()
{
  char buf = 0;
        struct termios old = {0};
        if (tcgetattr(0, &old) < 0)
                perror("tcsetattr()");
        old.c_lflag &= ~ICANON;
        old.c_lflag &= ~ECHO;
        old.c_cc[VMIN] = 1;
        old.c_cc[VTIME] = 0;
        if (tcsetattr(0, TCSANOW, &old) < 0)
                perror("tcsetattr ICANON");
        if (read(0, &buf, 1) < 0)
                perror ("read()");
        old.c_lflag |= ICANON;
        old.c_lflag |= ECHO;
        if (tcsetattr(0, TCSADRAIN, &old) < 0)
                perror ("tcsetattr ~ICANON");
        return (buf);
}