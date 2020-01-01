QT += widgets
requires(qtConfig(filedialog))
qtHaveModule(printsupport): QT += printsupport

SOURCES += \
    fenprincipale.cpp \
    main.cpp

HEADERS += \
    fenprincipale.h

RESOURCES += \
    ZeroClassGenerator.qrc
