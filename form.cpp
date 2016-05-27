#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}

void Form::setText(QString text)
{
    ui->label->setText(text);
    //ui->label->
    //ui->textBrowser->setText(text);
}
