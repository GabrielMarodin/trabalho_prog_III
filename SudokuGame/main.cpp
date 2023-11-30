#include "sudokugrid.h"

#include <QApplication>
#include "sudokugrid.h"
#include "sudoku.h"
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    srand(time(NULL));

    Sudoku *puzzle = new Sudoku();

    puzzle->createSeed();

    puzzle->genPuzzle();

    SudokuGrid w;
    w.fillGrid(puzzle);
    w.show();
    return a.exec();
}
