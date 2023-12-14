#ifndef SUDOKUGRID_H
#define SUDOKUGRID_H

#include <QtWidgets>
#include "sudoku.h"


class SudokuGrid : public QWidget
{
    Q_OBJECT
public:
    explicit SudokuGrid(Sudoku * s, QWidget *parent = nullptr);
    void fillGrid();

signals:


private slots:
    void processInput();
    void resolver();
    void validar();
    void regenerar();


private:
    QGridLayout  _layout;

    QLineEdit   _cells[9][9];
    QPushButton* b_resolver = new QPushButton("Resolver", this);
    QPushButton* b_validar = new QPushButton("Validar", this);
    QPushButton* b_regen = new QPushButton("Novo", this);
    Sudoku * _sudoku;
    int winFlag;

};

#endif // SUDOKUGRID_H
