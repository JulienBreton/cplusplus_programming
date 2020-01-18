#include <QApplication>
#include "fenprincipale.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    FenPrincipale * FenetrePrincipale = new FenPrincipale();
    FenetrePrincipale->show();

    return app.exec();
}
