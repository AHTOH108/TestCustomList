#include "mytablewidget.h"
#include "ui_mytablewidget.h"

MyTableWidget::MyTableWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyTableWidget)
{
    ui->setupUi(this);
    clearSelectItem();
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setShowGrid(true);
}

MyTableWidget::~MyTableWidget()
{
    delete ui;
}

void MyTableWidget::on_tableWidget_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn)
{
    goDeselectItem(previousRow, previousColumn);
    goSelectItem(currentRow, currentColumn);
}

void MyTableWidget::setData(TableX *tableX)
{
    this->tableX = tableX;
    updateTable();
}

void MyTableWidget::updateTable()
{
    QTime time = QTime::currentTime();

    int msec = time.msecsTo( QTime::currentTime() );
    int countRow = tableX->getCountRow();
    int countColumn = tableX->getCountColumn();

    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(countRow);
    ui->tableWidget->setColumnCount(countColumn);

    for (int i = 0; i < countRow; i++){
        //int p = tableX->getIdRow(i);
        int p = 1;
        QString str_2 = QString::number(p);
        ui->tableWidget->setVerticalHeaderItem(i, new QTableWidgetItem(str_2));
        for (int j = 0; j < countColumn; j++){

            if(i == 0){ // если первый проход то выставляем ширину и заголовки
                QString str_1 = QString::number(2);
                ui->tableWidget->setHorizontalHeaderItem(j, new QTableWidgetItem(str_1));
            }
            //int value = tableX->getValueByIndex(i, j);
            int value = 0;
            ui->tableWidget->setItem(i, j, new QTableWidgetItem(QString::number(value)));

        }
    }
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->resizeRowsToContents();
}

void MyTableWidget::clearSelectItem()
{
    selectRow = -1;
    selectColumn = -1;
}

void MyTableWidget::goSelectItem(int row, int column)
{
    int rowCount = ui->tableWidget->rowCount();
    if (row < 0 || row >= rowCount){
        return;
    }
    int columnCount = ui->tableWidget->columnCount();
    if (column < 0 || column >= columnCount){
        return;
    }

    for (int i = 0; i < rowCount; i++)
        ui->tableWidget->item(i, column)->setBackground(QColor(190,255,190,255));
    for (int j = 0; j < columnCount; j++)
        ui->tableWidget->item(row, j)->setBackground(QColor(190,255,190,255));

    ui->tableWidget->item(row, column)->setBackground(QColor(255,170,200,255));
    selectRow = row;
    selectColumn = column;
}

void MyTableWidget::goDeselectItem(int row, int column)
{
    int rowCount = ui->tableWidget->rowCount();
    if (row < 0 || row >= rowCount){
        return;
    }
    int columnCount = ui->tableWidget->columnCount();
    if (column < 0 || column >= columnCount){
        return;
    }

    for (int i = 0; i < rowCount; i++)
        ui->tableWidget->item(i, column)->setBackground(QColor(Qt::white));
    for (int j = 0; j < columnCount; j++)
        ui->tableWidget->item(row, j)->setBackground(QColor(Qt::white));

    if (row == selectRow){
        selectRow = -1;
    }
    if (column == selectColumn){
        selectColumn = -1;
    }
}











