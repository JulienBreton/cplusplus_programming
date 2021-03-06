QT += widgets
requires(qtConfig(filedialog))
qtHaveModule(printsupport): QT += printsupport

TEMPLATE = app

SOURCES += \
    fencodegenere.cpp \
    fenprincipale.cpp \
    main.cpp

HEADERS += \
    fencodegenere.h \
    fenprincipale.h

RESOURCES += \
    ZeroClassGenerator.qrc

TRANSLATIONS += \
    zeroclassgenerator_en.ts zeroclassgenerator_es.ts

FORMS += \
    form.ui
