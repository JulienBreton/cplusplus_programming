#ifndef CAT_H
#define CAT_H

#include <QObject>
#include <QDebug>

class Cat : public QObject
{
    Q_OBJECT
    //Ne pas oublier de changer le type de la propriété.
    Q_PROPERTY(QString nameCat READ name WRITE setName NOTIFY nameChanged)
public:
    explicit Cat(QObject *parent = nullptr);

signals:
    //Le signal est utilisé dans la partie QML pour par exemple modifier l'interface (afficher qlq chose...)
    void meow();
    void nameChanged();

public slots:
    void call();

private:
    QString name();
    void setName(QString value);
    QString m_name;
};

#endif // CAT_H
