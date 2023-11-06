#include "Sudoku.h"
using namespace std;

Sudoku::Sudoku()
{

}
int genRandNum(int maxLimit)
{
  return rand()%maxLimit;
}
bool FindUnassignedLocation(int grid[9][9], int &row, int &col)
{
    for (row = 0; row < 9; row++)
    {
        for (col = 0; col < 9; col++)
        {
            if (grid[row][col] == UNASSIGNED)
                return true;
        }
    }

    return false;
}

bool UsedInRow(int grid[9][9], int row, int num)
{
    for (int col = 0; col < 9; col++)
    {
        if (grid[row][col] == num)
            return true;
    }

    return false;
}

bool UsedInCol(int grid[9][9], int col, int num)
{
    for (int row = 0; row < 9; row++)
    {
        if (grid[row][col] == num)
            return true;
    }

    return false;
}

bool UsedInBox(int grid[9][9], int boxStartRow, int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (grid[row+boxStartRow][col+boxStartCol] == num)
                return true;
        }
    }

    return false;
}

bool isSafe(int grid[9][9], int row, int col, int num)
{
    return !UsedInRow(grid, row, num) && !UsedInCol(grid, col, num) && !UsedInBox(grid, row - row%3, col - col%3, num);
}

void Sudoku::fillEmptyDiagonalBox(int idx)
{
  int start = idx*3;
  random_shuffle(this->guessNum, (this->guessNum) + 9, genRandNum);
  for (int i = 0; i < 3; ++i)
  {
    for (int j = 0; j < 3; ++j)
    {
      this->grid[start+i][start+j] = guessNum[i*3+j];
    }
  }
}

bool Sudoku::solveGrid()
{
    int row, col;

    if (!FindUnassignedLocation(this->grid, row, col))
        return true;

    for (int num = 0; num < 9; num++)
    {
        if (isSafe(this->grid, row, col, this->guessNum[num]))
        {
            this->grid[row][col] = this->guessNum[num];

            if (solveGrid())
                return true;

            this->grid[row][col] = UNASSIGNED;
        }
    }

    return false;

}

void Sudoku::createSeed()
{
    this->fillEmptyDiagonalBox(0);
    this->fillEmptyDiagonalBox(1);
    this->fillEmptyDiagonalBox(2);

    this->solveGrid(); // pseudo-aleatorio

    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            this->solnGrid[i][j] = this->grid[i][j];
        }
    }
}

