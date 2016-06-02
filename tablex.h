#ifndef TABLEX_H
#define TABLEX_H

#include <QObject>

#include <QtCore>

typedef QMap<QString,int> MapRow;

class TableX : public QObject
{
    Q_OBJECT
public:
    explicit TableX(QObject *parent = 0);

    void addNewRow(int idRow);
    void addNewColumn(int idColumn);

    bool removeRow(int idRow);
    bool removeColumn(int idColumn);

    void setValue(int idRow, int idColumn, int value);
    void setValueByIndex(int row, int column, int value);
    int getValue(int idRow, int idColumn) { return map[intToString(idRow)][intToString(idColumn)]; }
    int getValueByIndex(int row, int column);

    int getCountRow() { return lstIdRow.size(); }
    int getCountColumn() { return lstIdColumn.size(); }

    int getIdRow(int row);
    int getIdColumn(int column);

private:
    QMap<QString, int> map_temp;

    QMap<QString, MapRow> map;

    QList <int> lstIdRow;
    QList <int> lstIdColumn;

    QString intToString(int k);
};


#endif // TABLEX_H
