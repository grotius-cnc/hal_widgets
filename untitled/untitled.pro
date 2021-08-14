QT       += core gui svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH+=/home/user/Qhalwidgets
LIBS+=-L/opt/qt-creator/Tools/QtCreator/lib/Qt/plugins/designer -lhalwidgetsplugin


#Lcnc
INCLUDEPATH+=   /opt/linuxcnc/include/ \
                /opt/linuxcnc/src/hal/ \
                /opt/linuxcnc/src/utils/ \
                /opt/linuxcnc/src/hal/utils/ \
                /opt/halview/ \

LIBS+= -L/opt/linuxcnc/lib/
LIBS+= -L/opt/linuxcnc/tcl/
LIBS+= -L/opt/halview/
LIBS+= -llinuxcnchal

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icon.qrc

