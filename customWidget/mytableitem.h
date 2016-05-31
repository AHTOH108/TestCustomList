#ifndef MYTABLEITEM_H
#define MYTABLEITEM_H

#include <QWidget>
#include <QTableWidgetItem>

class MyTableItem : public QTableWidgetItem
{
    //Q_OBJECT
public:
    //explicit MyTableItem(QWidget *parent = 0);
    explicit MyTableItem(int type = Type);
    explicit MyTableItem(const QString &text, int type = Type);
    explicit MyTableItem(const QIcon &icon, const QString &text, int type = Type);

    void setCount(int count) { this->count = count; }
    int getCount() { return count; }

private:
    int count;

    void iniData();
};

#endif // MYTABLEITEM_H
