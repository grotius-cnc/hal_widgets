#include "component.h"
#include <iostream>

component::component(QWidget *parent) :
    QWidget(parent),
    layout(new QGridLayout(this))
{
    int id=hal_init("gui");
    std::cout<<"component id:"<<id<<std::endl;
}
