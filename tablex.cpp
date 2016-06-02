#include "tablex.h"

TableX::TableX(QObject *parent) : QObject(parent)
{
    lstIdRow.clear();
    lstIdColumn.clear();
}

void TableX::addNewRow(int idRow)
{
    lstIdRow << idRow;
    QMap <QString, int> row;

    foreach (int id, lstIdColumn) {
       row[intToString(id)] = 0;
    }
    map[intToString(idRow)] = row;
    return;
}

void TableX::addNewColumn(int idColumn)
{
    lstIdColumn << idColumn;

    foreach (MapRow row, this->map) {
        row[intToString(idColumn)] = 0;
    }
    return;
}

bool TableX::removeRow(int idRow)
{

}

bool TableX::removeColumn(int idColumn)
{

}

void TableX::setValue(int idRow, int idColumn, int value)
{

}

void TableX::setValueByIndex(int row, int column, int value)
{
    map[intToString(lstIdRow[row])] [intToString(lstIdColumn[column])] = value;
}

int TableX::getValueByIndex(int row, int column)
{
    if (row >= 0 && row < lstIdRow.size() && column >= 0 && column < lstIdColumn.size()){
        return map[intToString(lstIdRow[row])] [intToString(lstIdColumn[column])];
    }
    else return -1;
}

int TableX::getIdRow(int row)
{
    if (row >= 0 && row < lstIdRow.size() ){
        return lstIdRow[row];
    }else{
        return -1;
    }
}

int TableX::getIdColumn(int column)
{
    if (column >= 0 && column < lstIdColumn.size() ){
        return lstIdColumn[column];
    }else{
        return -1;
    }
}

QString TableX::intToString(int k)
{
    return QString::number(k);
}

