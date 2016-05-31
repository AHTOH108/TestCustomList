#include "mytableitem.h"

//MyTableItem::MyTableItem(QWidget *parent) : QWidget(parent)
//{

//}


MyTableItem::MyTableItem(int type) : QTableWidgetItem(type)
{
    iniData();
}

MyTableItem::MyTableItem(const QString &text, int type) : QTableWidgetItem(text, type)
{
    iniData();
}

MyTableItem::MyTableItem(const QIcon &icon, const QString &text, int type) : QTableWidgetItem(icon, text, type)
{
    iniData();
}

void MyTableItem::iniData()
{
    count = 0;
}

