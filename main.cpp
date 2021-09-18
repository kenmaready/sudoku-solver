#include <iostream>
#include <string>
#include <conio.h>
#include "Sudoku.h"

using namespace std;

int main() {
  string filename {};

  cout << "Please enter the filename for your sudoku puzzle (including .txt extension): ";
  cin >> filename;


  Sudoku puzzle {filename};
  bool loaded {};
  loaded = puzzle.load_game();
  if (loaded) {
    cout << "\nYour puzzle has been loaded:" << endl;
  }

  puzzle.display();

  cout << "Press any key to solve." << endl;

  while (!kbhit());

  bool solved {};
  solved = puzzle.solve();
  if (solved) cout << "Your puzzle has been solved:" << endl;
  puzzle.show_solution();


  return 0;
}