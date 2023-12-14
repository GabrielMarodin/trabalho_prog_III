#include "sudokugrid.h"


SudokuGrid::SudokuGrid(Sudoku* s, QWidget *parent)
    : QWidget{parent}, _sudoku(s)
{


    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            _cells[i][j].setValidator(new QIntValidator(1,9,this));
            _cells[i][j].setStyleSheet(QString("border: 1px solid gray; width: 25px; height:25px;"));
            _cells[i][j].setFixedWidth(50);
            _cells[i][j].setFixedHeight(50);
            _cells[i][j].setAlignment(Qt::AlignCenter);
            _layout.addWidget(&_cells[i][j], i, j);
            connect(&_cells[i][j], SIGNAL(editingFinished()), this, SLOT(processInput()));
        }
    }

    _layout.addWidget(b_resolver,9,3);
    _layout.setAlignment(b_resolver,Qt::AlignCenter);

    _layout.addWidget(b_validar,9,4);
    _layout.setAlignment(b_validar,Qt::AlignCenter);

    _layout.addWidget(b_regen,9,5);
    _layout.setAlignment(b_regen,Qt::AlignCenter);

    connect(b_resolver,SIGNAL(clicked()),this,SLOT(resolver()));
    connect(b_validar,SIGNAL(clicked()),this,SLOT(validar()));
    connect(b_regen,SIGNAL(clicked()),this,SLOT(regenerar()));

    setLayout(&_layout);

    _layout.setSpacing(0);
    _layout.setContentsMargins(0, 0, 0, 0);
    _layout.setAlignment(Qt::AlignCenter);


    winFlag = 0;

    _sudoku->createSeed();
    _sudoku->genPuzzle();
}
void SudokuGrid::fillGrid(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            _cells[i][j].setText(QString::number(_sudoku->getCell(i,j)));
            if(_sudoku->getCell(i,j)){
                _cells[i][j].setDisabled(1);
            }

        }
    }
}

void SudokuGrid::processInput(){
    int c=0;
    QLineEdit* cell = qobject_cast<QLineEdit*>(sender());
    if( cell != NULL ) {
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(_cells[i][j].text().toInt()==_sudoku->getSolncell(i,j))
                    c++;
            }
        }
        std::cout<<"acertos: "<<c<<std::endl;
        if(c==81){
            winFlag = 1;
        }else{
            winFlag = 0;
        }
    }
}
void SudokuGrid::resolver(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
           _cells[i][j].setText(QString::number(_sudoku->getSolncell(i,j)));
        }
    }
    winFlag = 1;
}
void SudokuGrid::validar(){
    if (winFlag){
        std::cout<<"debug win"<<std::endl;
        QMessageBox::information(this,tr("Sudoku"),tr("Venceu."));
    }

}
void SudokuGrid::regenerar(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            _cells[i][j].setEnabled(1);
        }
    }
    _sudoku = new Sudoku();
    _sudoku->createSeed();
    _sudoku->genPuzzle();

    this->fillGrid();

}
