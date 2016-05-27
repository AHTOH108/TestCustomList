#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for(int i = 0; i < 10; i++){
        MyObject *newObject = new MyObject(this);
        newObject->setId(i);
        newObject->setName(generateString(100));
        addItems(newObject);
    }
    updateDataListWidget(listItems);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_add_clicked()
{
    addItemsString(ui->plainTextEdit->toPlainText());
    updateDataListWidget_2(listItemsString);
    ui->plainTextEdit->clear();
}

void MainWindow::addItems(MyObject *item)
{
    listItems.append(item);
}

void MainWindow::addItemsString(QString str)
{
    listItemsString.append(str);
}

void MainWindow::updateDataListWidget(QVector<MyObject *> list)
{
    for(int i = 0; i < list.size(); i++){
        QListWidgetItem *item = new QListWidgetItem;
        Form *myit = new Form(this);//
        myit->setText(list[i]->getName());
        //myit->setName(QString::number(i));
        //myit->setPriority(i);
        item->setSizeHint(myit->sizeHint());
        ui->listWidget->addItem(item);
        ui->listWidget->setItemWidget(item,myit);
        //connect(myit,SIGNAL(buttonClic(QString)),this,SLOT(delitem(QString)));
    }
}

void MainWindow::updateDataListWidget_2(QVector<QString> list)
{
   ui->listWidget_2->clear();
   ui->listWidget_2->resize(300,300);
   for (int i = 0; i < list.size(); i ++)
       ui->listWidget_2->addItem(list[i]);
}

QString MainWindow::generateString(int lenght)
{
    QString str = "";
    int rangeRandom = RANDOM_STRING.size();
    for (int i = 0; i < lenght; i++){
        int k = qrand() % rangeRandom;
        str.append(RANDOM_STRING[k]);
    }
    return str;
}

void MainWindow::on_listWidget_2_doubleClicked(const QModelIndex &index)
{
    if( !index.isValid() ) {
        return;
    }

    if(QListWidget* listWgt = dynamic_cast< QListWidget* >(sender())) {
        if(QListWidgetItem* item = listWgt->takeItem(index.row())) {
            delete item;
        }
    }
}

void MainWindow::on_listWidget_doubleClicked(const QModelIndex &index)
{
    if( !index.isValid() ) {
        return;
    }

    if(QListWidget* listWgt = dynamic_cast< QListWidget* >(sender())) {
        if(QListWidgetItem* item = listWgt->takeItem(index.row())) {
            delete item;
        }
    }
}
