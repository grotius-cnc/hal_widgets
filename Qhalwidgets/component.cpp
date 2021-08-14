#include "component.h"
#include <iostream>
int id=0;
component::component(QWidget *parent) :
    QWidget(parent),
    layout(new QGridLayout(this))
{
    //id=hal_init("gui");
     //std::cout<<"component init id:"<<id<<std::endl;
}

component::~component(){
    //hal_exit(id);
   // std::cout<<"component exit:"<<id<<std::endl;
}
