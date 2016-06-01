#include "mytablewidget.h"
#include "ui_mytablewidget.h"

MyTableWidget::MyTableWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyTableWidget)
{
    ui->setupUi(this);
}

MyTableWidget::~MyTableWidget()
{
    delete ui;
}

void MyTableWidget::on_tableWidget_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn)
{

}

void MyTableWidget::setData(TableX *tableX)
{
    this->tableX = tableX;
    updateTable();
}

void MyTableWidget::updateTable()
{
    int countRow = tableX->getCountRow();
    int countColumn = tableX->getCountColumn();

    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(countRow);
    ui->tableWidget->setColumnCount(countColumn);

    for (int i = 0; i < countRow; i++){

        QString str_2 = QString::number(tableX->getIdRow(i));
        ui->tableWidget->setVerticalHeaderItem(i, new QTableWidgetItem(str_2));
        for (int j = 0; j < countColumn; j++){

            if(i == 0){ // если первый проход то выставляем ширину и заголовки
                QString str_1 = QString::number(tableX->getIdColumn(j));
                ui->tableWidget->setHorizontalHeaderItem(j, new QTableWidgetItem(str_1));
            }

            ui->tableWidget->setItem(i, j, new QTableWidgetItem(QString::number(tableX->getValueByIndex(i, j))));

        }
    }
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->resizeRowsToContents();
}
