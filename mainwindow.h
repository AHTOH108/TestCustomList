#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <form.h>
#include <QColor>
#include <QMessageBox>

#include "customWidget/mytableitem.h"
#include "object/myobject.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_add_clicked();

    void on_listWidget_2_doubleClicked(const QModelIndex &index);

    void on_listWidget_doubleClicked(const QModelIndex &index);

    void on_pushButton_genData_clicked();

    void on_pushButton_clicked();

    void on_tableWidget_doubleClicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;

    const QString RANDOM_STRING = "qwerty uiop[]asdfg hjkl;'zxc vbnm,./ йцу кенгшщз хъфыва пролдж эячсмитьб ю. 12345 678 90";

    QVector <MyObject*> listItems;
    QVector <QString> listItemsString;

    // Method's ************

    void addItems(MyObject* item);
    void addItemsString(QString str);

    void updateDataListWidget(QVector <MyObject*> list);
    void updateDataListWidget_2(QVector <QString> list);

    QString generateString(int lenght);

    void createTables();
    void updateTable(QVector <QString> list);

    void showMessage(QString text);

};

#endif // MAINWINDOW_H
