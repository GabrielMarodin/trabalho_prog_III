#ifndef SUDOKUGRID_H
#define SUDOKUGRID_H

#include <QtWidgets>
#include <string>
#include "sudoku.h"

class SudokuGrid : public QWidget
{
    Q_OBJECT
public:
    explicit SudokuGrid(QWidget *parent = nullptr);
    void fillGrid(Sudoku*);

signals:


private slots:
    //void processInput();


private:
    QGridLayout  _layout;

    QLineEdit   _cells[9][9];

};

#endif // SUDOKUGRID_H