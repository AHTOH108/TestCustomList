#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <QObject>

class MyObject : public QObject
{
    Q_OBJECT
public:
    explicit MyObject(QObject *parent = 0);

    int getId() const;
    void setId(int value);
    QString getName() const;
    void setName(const QString &value);
    bool getIsEnabled() const;
    void setIsEnabled(bool value);

private:
    int id;
    QString name;
    bool isEnabled;

};

#endif // MYOBJECT_H
