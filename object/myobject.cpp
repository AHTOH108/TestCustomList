#include "myobject.h"

MyObject::MyObject(QObject *parent) : QObject(parent)
{
    id = 0;
    name = "";
    isEnabled = true;
}

int MyObject::getId() const
{
    return id;
}

void MyObject::setId(int value)
{
    id = value;
}

QString MyObject::getName() const
{
    return name;
}

void MyObject::setName(const QString &value)
{
    name = value;
}

bool MyObject::getIsEnabled() const
{
    return isEnabled;
}

void MyObject::setIsEnabled(bool value)
{
    isEnabled = value;
}

