#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#define UNASSIGNED 0

class Sudoku
{
public:
    Sudoku();

private:
    int grid[9][9];
    int solnGrid[9][9];
    int guessNum[9];
    int gridPos[81];
};

#endif // SUDOKU_H
