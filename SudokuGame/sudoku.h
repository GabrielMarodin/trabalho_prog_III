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
    void fillEmptyDiagonalBox(int);
    void countSoln(int &number);
    void createSeed();
    bool solveGrid();
    void genPuzzle();
    void printGrid();
    int getCell(int ,int );
    int getSolncell(int,int);
private:
    int grid[9][9];
    int solnGrid[9][9];
    int guessNum[9];
    int gridPos[81];
    bool grid_status;
};

#endif // SUDOKU_H
