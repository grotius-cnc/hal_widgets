#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QDebug>
#include <QMetaProperty>
#include <vector>
#include <utility>
#include <algorithm>

void dump_props(QObject *o);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    hal_init("gui");

    QList<QObject*> list = centralWidget()->findChildren<QObject*>();
    foreach (auto obj, list) {
        // dump_props(obj); // Prints widget info.
        // std::cout<<""<<std::endl;

        auto *o = obj->metaObject();
        if(o->className()==QString("button")){
            // std::cout<<"button class found"<<std::endl;
            obj->setProperty("property_hal_live_mode", QVariant(bool(true)));
        }
    }
}

MainWindow::~MainWindow()
{
    system("/opt/linuxcnc/scripts/halrun -U");
    delete ui;
}

void dump_props(QObject *o)
{
    auto mo = o->metaObject();
    qDebug() << "## Properties of" << o << "##";
    do {
        qDebug() << "### Class" << mo->className() << "###";
        std::vector<std::pair<QString, QVariant> > v;
        v.reserve(mo->propertyCount() - mo->propertyOffset());
        for (int i = mo->propertyOffset(); i < mo->propertyCount();
             ++i)
            v.emplace_back(mo->property(i).name(),
                           mo->property(i).read(o));
        std::sort(v.begin(), v.end());
        for (auto &i : v)
            qDebug() << i.first << "=>" << i.second;
    } while ((mo = mo->superClass()));
}
