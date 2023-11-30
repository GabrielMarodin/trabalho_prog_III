#include "sudokugrid.h"


SudokuGrid::SudokuGrid(QWidget *parent)
    : QWidget{parent}
{
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            _cells[i][j].setValidator(new QIntValidator(1,9,this));
            _layout.addWidget(&_cells[i][j], i, j);
            //connect(&_cells[i][j], SIGNAL(editingFinished()), this, SLOT(processInput()));
        }
    }

    setLayout(&_layout);
    _layout.setSpacing(0);
}
void SudokuGrid::fillGrid(Sudoku* Sudoku){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            _cells[i][j].setText(QString::number(Sudoku->getCell(i,j)));
            if(Sudoku->getCell(i,j)){
                _cells[i][j].setDisabled(1);
            }

        }
    }
}

/*void SudokuGrid::processInput(){

    QLineEdit* cell = qobject_cast<QLineEdit*>(sender());
    if( cell != NULL ) {
        break;
    }
}*/
