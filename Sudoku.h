#ifndef _SUDOKU_H_
#define _SUDOKU_H_

#include <string>
#include <fstream>
#include <vector>

class IOException: public std::exception {
  virtual const char *what() const noexcept {
    return "I/O Error: There was a problem loading your file.";
  }
};


class Sudoku {

  private:
    static const int ROWS {9};
    static const int COLUMNS {9};

  friend void display_board(const int board [ROWS][COLUMNS]);
  friend void copy_board(const int board [ROWS][COLUMNS], int new_board[ROWS][COLUMNS]);
  friend std::vector<int> check_row(const int board [ROWS][COLUMNS], int i, std::vector<int> &valid_numbers);
  friend std::vector<int> check_column(const int board [ROWS][COLUMNS], int j, std::vector<int> &valid_numbers);
  friend std::vector<int> find_valid_numbers(int board [ROWS][COLUMNS], int i, int j);

  public:
    int gameboard [ROWS][COLUMNS] {0};
    int solution [ROWS][COLUMNS] {0};
    bool solved {false};
    std::string filename {};

    Sudoku();
    Sudoku(std::string filename);
    void set_filename(std::string filename);
    bool load_game();
    void display();
    bool solve();
    bool solve(int board [ROWS][COLUMNS]);
    void show_solution();
    ~Sudoku();

};

#endif