#include "button.h"
#include <qdebug.h>

button::button(QWidget *parent) :
    QWidget(parent),
    layout(new QGridLayout(this)),
    buttons(new QPushButton(name))
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    layout->addWidget(buttons,0,0);

    QObject::connect(buttons,SIGNAL(pressed()),SLOT(button_pressed()));
    QObject::connect(buttons,SIGNAL(released()),SLOT(button_released()));

    // comp_idx = hal_init("gui");
 //   comp.data=halpr_find_comp_by_name("gui");

    // hal_ready(comp_idx);
}

button::haltype button::read_type(){
    return t;
}
void button::write_type(button::haltype property_type){
    t=property_type;

//    if(property_type==haltype::NONE){

//    }
//    if(property_type==haltype::HAL_BIT_OUT){
//        pin_bit = (bit_data_t*)hal_malloc(sizeof(bit_data_t));
//        hal_pin_bit_new(buttons->text().toStdString().c_str(),HAL_OUT,&(pin_bit->pin),comp.data->comp_id);
//    }
//    if(property_type==haltype::HAL_BIT_PARAM_RW){
//        param_bit = (param_bit_data_t*)hal_malloc(sizeof(param_bit_data_t));
//        hal_param_bit_new(buttons->text().toStdString().c_str(),HAL_RW,&(param_bit->pin),comp.data->comp_id);
//    }
 }

QString button::readname(){
    return name;
}

void button::writename(QString property_hal_name){
    name=property_hal_name;

    QObject::setObjectName(name);
    buttons->setText(name);


}

bool button::read_live_mode(){
    return live_mode;
}

void button::write_live_mode(bool property_hal_live_mode){
    live_mode=property_hal_live_mode;
}

void button::button_pressed(){
    //*pin_bit->pin=1;
}

void button::button_released(){
    //*pin_bit->pin=0;
}

