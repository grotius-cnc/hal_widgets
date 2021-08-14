
To view or refresh installed plugins :
Menubar -> Tools -> Form editor -> About qt designer plugins

https://user-images.githubusercontent.com/44880102/129457468-5d5a409c-d07a-4fa6-9d05-1694b3d1d3b6.mp4

Work in progress. Have a look at the button.h / button.cpp file.

![buttonclass](https://user-images.githubusercontent.com/44880102/129457476-1e958650-0b80-4913-b90b-ab39967ec7ed.jpg)

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
