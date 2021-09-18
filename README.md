# sudoku-solver

This is a personal project to test myself while learning C++. It's a brute-force sudoku-solver, meaning that it steps through a sudoku puzzle until it finds an empty cell, then checks to find all valid numbers for that cell by knocking out conflicts based on the numbers already in place in the same row and column (and eventually the cell's 3x3 grid). Then it creates a new hypothetical puzzle board with each of those possibilities and recursively checks all possibilities for the next cell. And so on until an entire board is filled (with unworkable solutions being thrown out along the way) with that board becoming the solution.

Currently it only checks the row and column for conflicts, so it can solve "easy" puzzles (puzzles with a lot of numbers already filled in) correctly, but with more difficult puzzles it can arrive at an 'illegal' solution violating the rule prohibiting the same number appearing more than once in a 3x3 grid. I will implement that 3x3 grid-check in the next version.

## To run:

Run the `main.exe` file from the directory in which you save this. The terminal will prompt you to enter a filename for a puzzle you want to solve. `puzzle1.txt` and `puzzle2.txt` have been provided as examples. Currently, the solver solves puzzle1 correctly, but will arrive at an 'illegal' solution for puzzle2. Once I implement the 3x3 grid-check it should solve that one correctly as well.

## Format for puzzle files:

The format for the puzzle files is a .txt file containing 3-integer sets where the integers represent:\
`x y val`

where `x` is the row number (1-9) of the cell you're instructing the program to fill, `y` is the column number (1-9) and `val` is the value (1-9) you want to put in that cell. There should be no header row or other data in the file. For example, the first ten rows of puzzle1.txt look like this:  
`1 2 6`\
`1 3 9`\
`1 5 1`\
`1 6 5`\
`1 7 7`\
`1 9 8`\
`2 1 5`\
`2 4 7`\
`2 6 3`\
`2 7 2`

(Note that each cell's instruction does not need to be on a new line, it is just easier to read and check that way.)

This code has not yet been optimized in any way. I plan to reformat it to work expressly with pointers and to instantiate the 2d-arrays on the heap in order to improve performance.
