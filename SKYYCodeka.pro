QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#Executable Icon
win64:RC_ICONS += SoftwareIcon.ico
win32:RC_ICONS += SoftwareIcon.ico

SOURCES += \
    automatons.cpp \
    codeeditor.cpp \
    dialogpopup.cpp \
    linenumberarea.cpp \
    main.cpp \
    mainwindow.cpp \
    token.cpp \
    workercompiler.cpp \
    workerfilehandler.cpp

HEADERS += \
    automatons.h \
    codeeditor.h \
    dialogpopup.h \
    linenumberarea.h \
    mainwindow.h \
    token.h \
    workercompiler.h \
    workerfilehandler.h

FORMS += \
    dialogpopup.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
