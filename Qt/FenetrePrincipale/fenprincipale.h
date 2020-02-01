#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H

#include <QMainWindow>
#include <QLineEdit>
#include <QFormLayout>
#include <QMdiArea>
#include <QTextEdit>
#include <QToolBar>
#include <QFontComboBox>

QT_BEGIN_NAMESPACE
namespace Ui { class FenPrincipale; }
QT_END_NAMESPACE

class FenPrincipale : public QMainWindow
{
    Q_OBJECT

public:
    FenPrincipale(QWidget *parent = nullptr);
    ~FenPrincipale();

private:
    Ui::FenPrincipale *ui;
};
#endif // FENPRINCIPALE_H
