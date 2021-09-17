#include <iostream>
#include "Sudoku.h"

using namespace std;

int main() {
  Sudoku puzzle1 {"puzzle1.txt"};
  cout << "puzzle1:" << endl;
  puzzle1.display();

  bool loaded {};
  loaded = puzzle1.load_game();

  if (loaded) {
    cout << "Your puzzle has been loaded." << endl;
  }

  puzzle1.display();
  bool solved {};
  solved = puzzle1.solve();
  if (solved) cout << "puzzle1 has been solved." << endl;
  puzzle1.show_solution();

  return 0;
}