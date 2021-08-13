CONFIG      += core plugin debug_and_release
TARGET      = $$qtLibraryTarget(halwidgetsplugin)
TEMPLATE    = lib

HEADERS     = componentplugin.h buttonplugin.h labelplugin.h ledplugin.h sliderplugin.h gcodeplugin.h halwidgets.h
SOURCES     = componentplugin.cpp buttonplugin.cpp labelplugin.cpp ledplugin.cpp sliderplugin.cpp gcodeplugin.cpp halwidgets.cpp
RESOURCES   = icons.qrc
LIBS        += -L. 

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

include(label.pri)
include(gcode.pri)
include(slider.pri)
include(component.pri)
include(button.pri)
include(led.pri)

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

# Create a .so simlink to : /opt/qt-creator/Tools/QtCreator/lib/Qt/plugins/designer
