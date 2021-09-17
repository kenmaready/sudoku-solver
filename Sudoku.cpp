#include <iostream>
#include <iomanip>
#include "Sudoku.h"




// helper functions:
void print_vec(std::vector<int> vec) {
  std::cout << "vector < ";
  for (auto i: vec) {
    std::cout << i << " ";
  }
  std::cout << ">" << std::endl;
}

void copy_board(const int board [Sudoku::ROWS][Sudoku::COLUMNS], int new_board[Sudoku::ROWS][Sudoku::COLUMNS]) {
  for (int i {0}; i < Sudoku::ROWS; i++) {
    for (int j {0}; j < Sudoku::COLUMNS; j++) {
      new_board[j][i] = board[j][i];
    }
  }
}

void display_board(const int board [Sudoku::ROWS][Sudoku::COLUMNS]) {
  std::cout << std::endl;
  std::cout << std::setw(25) << std::setfill('-') << "" << std::endl;
  std::cout << std::setfill(' ');
  for (int i{0}; i < Sudoku::ROWS; i++) {
    for (int j(0); j < Sudoku::COLUMNS; j++) {
      if (j == 0) {
        std::cout << "| ";
      }
      std::cout << (board[j][i] == 0 ? "." : std::to_string(board[j][i])) << " ";
      if ((j+1) % 3 == 0) {
        std::cout << "| ";
      }
    }
    std::cout << std::endl;
    if ((i+1) % 3 == 0) {
      std::cout << std::setw(25) << std::setfill('-') << "" << std::endl;
      std::cout << std::setfill(' ');
    }
  }
  std::cout << std::endl;
}


std::vector<int> check_row(const int board [Sudoku::ROWS][Sudoku::COLUMNS], int i, std::vector<int> &valid_numbers) {
  for (int x {0}; x < Sudoku::COLUMNS; x++) {
    int size_y = valid_numbers.size() - 1;
    for (int y {size_y}; y >= 0; y--) {
      if (board[x][i] == valid_numbers.at(y)) {
        valid_numbers.erase(valid_numbers.begin() + y);
        continue;
      }
    }
  }
  // std::cout << "remaining valid_numbers (check_row): ";
  // print_vec(valid_numbers); 
  
  return valid_numbers;
}

std::vector<int> check_column(const int board [Sudoku::ROWS][Sudoku::COLUMNS], int j, std::vector<int> &valid_numbers) {
  for (int x {0}; x < Sudoku::ROWS; x++) {
    int size_y = valid_numbers.size() - 1;
    for (int y {size_y}; y >= 0; y--) {
      if (board[j][x] == valid_numbers.at(y)) {
        valid_numbers.erase(valid_numbers.begin() + y);
        continue;
      }
    }
  }
  // std::cout << "remaining valid_numbers (check_column): ";
  // print_vec(valid_numbers); 
  
  return valid_numbers;
}


std::vector<int> find_valid_numbers(int board [Sudoku::ROWS][Sudoku::COLUMNS], int i, int j) {
  // initialize vector with all valid numbers:
  std::vector<int> valid_numbers {};
  for (int num{1}; num <= 9; num++) {
    valid_numbers.push_back(num);
  }

  // check various ways for valid numbers, eliminating non-valid ones:
  valid_numbers = check_row(board, i, valid_numbers);
  valid_numbers = check_column(board, j, valid_numbers);
  
  return valid_numbers;
}

Sudoku::Sudoku() {};
Sudoku::Sudoku(std::string filename): filename{filename} {};

void Sudoku::set_filename(std::string filename) {
  (*this).filename = filename;
}

bool Sudoku::load_game() {
  if (filename.empty()) {
    std::cout << "No filename has been provided for this puzzle. You must provide a filename before loading the puzzle." << std::endl;
    return false;
  }

  std::ifstream game_loader(filename);
  if (!game_loader) {
    throw IOException();
  }

  int x, y, val;

  while (game_loader >> x >> y >> val) {
      gameboard[y-1][x-1] = val;
  }
  return true;
}



void Sudoku::display() {
  std::cout << std::endl;
  std::cout << std::setw(25) << std::setfill('-') << "" << std::endl;
  std::cout << std::setfill(' ');
  for (int i{0}; i < ROWS; i++) {
    for (int j(0); j < COLUMNS; j++) {
      if (j == 0) {
        std::cout << "| ";
      }
      std::cout << (gameboard[j][i] == 0 ? "." : std::to_string(gameboard[j][i])) << " ";
      if ((j+1) % 3 == 0) {
        std::cout << "| ";
      }
    }
    std::cout << std::endl;
    if ((i+1) % 3 == 0) {
      std::cout << std::setw(25) << std::setfill('-') << "" << std::endl;
      std::cout << std::setfill(' ');
    }
  }
  std::cout << std::endl;
}

bool Sudoku::solve() {
  return solve(gameboard);
}

bool Sudoku::solve(int board [ROWS][COLUMNS]) {
  int test_board [ROWS][COLUMNS] {};
  // std::copy(board, board + (ROWS * COLUMNS), test_board);
  
  for (int i{0}; i < ROWS; i++) {
    for (int j{0}; j < COLUMNS; j++) {
      if (board[j][i] == 0) {
        std::vector<int> valid_numbers {};
        valid_numbers = find_valid_numbers(board, i, j);
        if (valid_numbers.empty()) return false;
        else {
          for (int num: valid_numbers) {
            int new_board [ROWS][COLUMNS] {};
            copy_board(board, new_board);
            new_board[j][i] = num;
            bool solved = solve(new_board);
            if (solved) {
              if (!(*this).solved) {
              copy_board(new_board, solution);
              // std::cout << "Solution: " << std::endl;
              // display_board(solution);
              (*this).solved = true;
              }
              return true;
            }
          }
          return false;
        }
      }
    }
  }
  return true;
}

void Sudoku::show_solution() {
  display_board(solution);
}

Sudoku::~Sudoku() {};