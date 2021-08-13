![hal_announcement](https://user-images.githubusercontent.com/44880102/129305157-38324666-4a73-4a5d-88e6-fbdc614c0ecc.jpg)
# hal_widgets
hal widgets to create a gui app. 

- Drag and drop hal widgets

To install the plugin :

1. Create a .so simlink to : /opt/qt-creator/Tools/QtCreator/lib/Qt/plugins/designer
2. Create a new qt gui project, the .pro file requirements :

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
