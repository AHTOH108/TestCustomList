#ifndef MYTABLEWIDGET_H
#define MYTABLEWIDGET_H

#include <QWidget>

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


    void updateTable();

};

#endif // MYTABLEWIDGET_H
