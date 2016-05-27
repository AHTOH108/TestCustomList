#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
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
        Form *myit = new Form(this);
        myit->setText(list[i]->getName());
        item->setSizeHint(myit->sizeHint());
        item->setFlags( Qt::ItemIsEditable | Qt::ItemIsEnabled );
        ui->listWidget->addItem(item);
        ui->listWidget->setItemWidget(item,myit);
        //connect(myit,SIGNAL(buttonClic(QString)),this,SLOT(delitem(QString)));
    }
}

void MainWindow::updateDataListWidget_2(QVector<QString> list)
{
   ui->listWidget_2->clear();
   //ui->listWidget_2->resize(300,300);
   for (int i = 0; i < list.size(); i ++){
       QListWidgetItem *item = new QListWidgetItem;
       QColor color = QColor (240, 240, 240, 200);
       item->setBackgroundColor(color);
       item->setText(list[i]);
       ui->listWidget_2->addItem(item);
       //ui->listWidget_2->addItem(list[i]);
   }
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

void MainWindow::on_pushButton_genData_clicked()
{

    for(int i = 0; i < 20; i++){
        QString str = generateString(qrand() % 500);
        MyObject *newObject = new MyObject(this);
        newObject->setId(i);
        newObject->setName(str);
        addItems(newObject);
    }
    updateDataListWidget(listItems);
}

void MainWindow::on_pushButton_add_clicked()
{
    for(int i = 0; i < 50; i++){
        QString str = generateString(qrand() % 500);
        addItemsString(str);
    }
    updateDataListWidget_2(listItemsString);

    ui->plainTextEdit->clear();
}

