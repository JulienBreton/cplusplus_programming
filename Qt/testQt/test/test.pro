QT += widgets
requires(qtConfig(filedialog))
qtHaveModule(printsupport): QT += printsupport

SOURCES += \
    mafenetre.cpp \
    main.cpp \
    textedit.cpp \
    windowtablesettings.cpp

HEADERS += \
    mafenetre.h \
    textedit.h \
    windowtablesettings.h

RESOURCES += \
    textedit.qrc
