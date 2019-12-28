QT += widgets
requires(qtConfig(filedialog))
qtHaveModule(printsupport): QT += printsupport

SOURCES += \
    mafenetre.cpp \
    main.cpp \
    textedit.cpp

HEADERS += \
    mafenetre.h \
    textedit.h

RESOURCES += \
    textedit.qrc
