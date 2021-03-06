#include <QApplication>
#include "fenprincipale.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QString locale = QLocale::system().name().section('_', 0, 0);

    QTranslator translator;
    translator.load(QString("zeroclassgenerator_") + locale);
    translator.load(QString("qt_") + locale, QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    app.installTranslator(&translator);

    FenPrincipale * FenetrePrincipale = new FenPrincipale();
    FenetrePrincipale->show();

    return app.exec();
}
