#ifndef MYTABLEWIDGET_H
#define MYTABLEWIDGET_H

#include <QWidget>
#include <QTime>
#include <QDebug>
#include "tablex.h"

namespace Ui {
class MyTableWidget;
}

class MyTableWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyTableWidget(QWidget *parent = 0);
    ~MyTableWidget();

    void setData(TableX *tableX);

private slots:
    void on_tableWidget_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn);

private:
    Ui::MyTableWidget *ui;

    TableX *tableX;

    int selectRow;
    int selectColumn;


    void updateTable();
    void clearSelectItem();
    void goSelectItem(int row, int column);
    void goDeselectItem(int row, int column);

};

#endif // MYTABLEWIDGET_H
