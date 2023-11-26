#include "sudokugrid.h"


SudokuGrid::SudokuGrid(QWidget *parent)
    : QWidget{parent}
{
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            _layout.addWidget(&_cells[i][j], i, j);

        }
    }

    setLayout(&_layout);
}
void SudokuGrid::fillGrid(Sudoku* Sudoku){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            _cells[i][j].setText(QString::number(Sudoku->getCell(i,j)));
            if(!_cells[i][j].text().toInt()){
                _cells[i][j].setDisabled(1);
            }

        }
    }
}
