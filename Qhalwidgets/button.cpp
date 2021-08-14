#include "button.h"
#include "iostream"
int compidx=0;

button::button(QWidget *parent) :
    QWidget(parent),
    layouts(new QGridLayout(this)),
    buttons(new QPushButton(name,this))
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    layouts->addWidget(buttons,0,0);

    layouts->setMargin(0);
    buttons->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
}

button::haltype button::read_type(){
    return t;
}

void button::write_type(button::haltype property_type){
    t=property_type;
}

QIcon button::read_icon_pressed(){
    return icon_pressed;
}

void button::write_icon_pressed(QIcon property_icon_pressed){
    icon_pressed=property_icon_pressed;

    read_buttonstate();
    write_buttonstate(b_state);

}

QIcon button::read_icon_released(){
    return icon_released;
}

void button::write_icon_released(QIcon property_icon_released){
    icon_released=property_icon_released;

    read_buttonstate();
    write_buttonstate(b_state);
}

button::buttonstate button::read_buttonstate(){
    return b_state;
}

void button::write_buttonstate(buttonstate property_buttonstate){
    b_state=property_buttonstate;

    if(b_state==buttonstate::NORMAL_OFF){
        buttons->setDown(false);
        buttons->setStyleSheet(style_released);
        buttons->setIcon(icon_released);
        buttons->setIconSize(icon_size_released);
        buttons->update();
    }
    if(b_state==buttonstate::NORMAL_ON){
        buttons->setDown(true);
        buttons->setStyleSheet(style_pressed);
        buttons->setIcon(icon_pressed);
        buttons->setIconSize(icon_size_pressed);
        buttons->update();
    }

    if(b_state==buttonstate::TOGGLE_OFF){
        buttons->setCheckable(true);
        buttons->setDown(false);
        buttons->setStyleSheet(style_released);
        buttons->setIcon(icon_released);
        buttons->setIconSize(icon_size_released);
        buttons->update();
    }
    if(b_state==buttonstate::TOGGLE_ON){
        buttons->setCheckable(true);
        buttons->setDown(true);
        buttons->setStyleSheet(style_pressed);
        buttons->setIcon(icon_pressed);
        buttons->setIconSize(icon_size_pressed);
        buttons->update();
    }
}

QSize button::read_icon_size_pressed(){
    return icon_size_pressed;
}

void button::write_icon_size_pressed(QSize property_icon_size_pressed){
    icon_size_pressed=property_icon_size_pressed;

    read_buttonstate();
    write_buttonstate(b_state);
}


QSize button::read_icon_size_released(){
    return icon_size_released;
}

void button::write_icon_size_released(QSize property_icon_size_released){
    icon_size_released=property_icon_size_released;

    read_buttonstate();
    write_buttonstate(b_state);
}


QColor button::read_color_pressed(){
    return color_pressed;
}

void button::write_color_pressed(QColor property_color_pressed){
    color_pressed=property_color_pressed;

    // style_pressed = color_pressed.name(QColor::HexArgb); //#00ffffff
    QString col=color_pressed.name(QColor::HexArgb);
    style_pressed="background: "+col+";";

    read_buttonstate();
    write_buttonstate(b_state);
}

QColor button::read_color_released(){
    return color_released;
}

void button::write_color_released(QColor property_color_released){
    color_released=property_color_released;

    // style_pressed = color_pressed.name(QColor::HexArgb); //#00ffffff
    QString col=color_released.name(QColor::HexArgb);
    style_released="background: "+col+";";

    read_buttonstate();
    write_buttonstate(b_state);
}

QString button::read_value_pressed(){
    return value_pressed;
}

void button::write_value_pressed(QString property_hal_value_pressed){
    value_pressed=property_hal_value_pressed;
}

QString button::read_value_released(){
    return value_released;
}

void button::write_value_released(QString property_hal_value_released){
    value_released=property_hal_value_released;
}

QString button::read_name(){
    return name;
}

void button::write_name(QString property_hal_name){
    name=property_hal_name;

    QObject::setObjectName(name);
    buttons->setText(name);
}

bool button::read_live_mode(){
    return live_mode;
}

void button::write_live_mode(bool property_hal_live_mode){

    if(b_state==buttonstate::NORMAL_OFF || b_state==buttonstate::NORMAL_ON){
        QObject::connect(buttons,SIGNAL(pressed()),SLOT(button_pressed()));
        QObject::connect(buttons,SIGNAL(released()),SLOT(button_released()));
    }
    if(b_state==buttonstate::TOGGLE_OFF || b_state==buttonstate::TOGGLE_ON){
        QObject::connect(buttons,SIGNAL(toggled(bool)),SLOT(button_toggled(bool)));
    }


    live_mode=property_hal_live_mode;

    if(t==haltype::HAL_BIT_IN){
        pin_bit = (bit_data_t*)hal_malloc(sizeof(bit_data_t));
        hal_pin_bit_new(buttons->text().toStdString().c_str(),HAL_IN,&(pin_bit->pin),halpr_find_comp_by_name(comp_name)->comp_id);
    }
    if(t==haltype::HAL_BIT_OUT){
        pin_bit = (bit_data_t*)hal_malloc(sizeof(bit_data_t));
        hal_pin_bit_new(buttons->text().toStdString().c_str(),HAL_OUT,&(pin_bit->pin),halpr_find_comp_by_name(comp_name)->comp_id);
    }
    if(t==haltype::HAL_BIT_PARAM_RW){
        param_bit = (bit_param_data_t*)hal_malloc(sizeof(bit_param_data_t));
        hal_param_bit_new(buttons->text().toStdString().c_str(),HAL_RW,&(param_bit->pin),halpr_find_comp_by_name(comp_name)->comp_id);
    }
    if(t==haltype::HAL_FLOAT_IN){
        pin_float = (float_data_t*)hal_malloc(sizeof(float_data_t));
        hal_pin_float_new(buttons->text().toStdString().c_str(),HAL_IN,&(pin_float->pin),halpr_find_comp_by_name(comp_name)->comp_id);
    }
    if(t==haltype::HAL_FLOAT_OUT){
        pin_float = (float_data_t*)hal_malloc(sizeof(float_data_t));
        hal_pin_float_new(buttons->text().toStdString().c_str(),HAL_OUT,&(pin_float->pin),halpr_find_comp_by_name(comp_name)->comp_id);
    }
    if(t==haltype::HAL_FLOAT_PARAM_RW){
        param_float = (float_param_data_t*)hal_malloc(sizeof(float_param_data_t));
        hal_param_float_new(buttons->text().toStdString().c_str(),HAL_RW,&(param_float->pin),halpr_find_comp_by_name(comp_name)->comp_id);
    }
    if(t==haltype::HAL_S32_IN){
        pin_s32 = (s32_data_t*)hal_malloc(sizeof(s32_data_t));
        hal_pin_s32_new(buttons->text().toStdString().c_str(),HAL_IN,&(pin_s32->pin),halpr_find_comp_by_name(comp_name)->comp_id);
    }
    if(t==haltype::HAL_S32_OUT){
        pin_s32 = (s32_data_t*)hal_malloc(sizeof(s32_data_t));
        hal_pin_s32_new(buttons->text().toStdString().c_str(),HAL_OUT,&(pin_s32->pin),halpr_find_comp_by_name(comp_name)->comp_id);
    }
    if(t==haltype::HAL_S32_PARAM_RW){
        param_s32 = (s32_param_data_t*)hal_malloc(sizeof(s32_param_data_t));
        hal_param_s32_new(buttons->text().toStdString().c_str(),HAL_RW,&(param_s32->pin),halpr_find_comp_by_name(comp_name)->comp_id);
    }
    if(t==haltype::HAL_U32_IN){
        pin_u32 = (u32_data_t*)hal_malloc(sizeof(u32_data_t));
        hal_pin_u32_new(buttons->text().toStdString().c_str(),HAL_IN,&(pin_u32->pin),halpr_find_comp_by_name(comp_name)->comp_id);
    }
    if(t==haltype::HAL_U32_OUT){
        pin_u32 = (u32_data_t*)hal_malloc(sizeof(u32_data_t));
        hal_pin_u32_new(buttons->text().toStdString().c_str(),HAL_OUT,&(pin_u32->pin),halpr_find_comp_by_name(comp_name)->comp_id);
    }
    if(t==haltype::HAL_U32_PARAM_RW){
        param_u32 = (u32_param_data_t*)hal_malloc(sizeof(u32_param_data_t));
        hal_param_u32_new(buttons->text().toStdString().c_str(),HAL_RW,&(param_u32->pin),halpr_find_comp_by_name(comp_name)->comp_id);
    }
    if(t==haltype::HAL_PORT_IN){
        pin_port = (port_data_t*)hal_malloc(sizeof(port_data_t));
        hal_pin_port_new(buttons->text().toStdString().c_str(),HAL_IN,&(pin_port->pin),halpr_find_comp_by_name(comp_name)->comp_id);
    }
    if(t==haltype::HAL_PORT_OUT){
        pin_port = (port_data_t*)hal_malloc(sizeof(port_data_t));
        hal_pin_port_new(buttons->text().toStdString().c_str(),HAL_OUT,&(pin_port->pin),halpr_find_comp_by_name(comp_name)->comp_id);
    }
    if(t==haltype::HAL_COMP){
        hal_init(buttons->text().toStdString().c_str());
    }

    // Initialise the button value.
    if(b_state==buttonstate::NORMAL_OFF){
        button_released();
    }
    if(b_state==buttonstate::NORMAL_ON){
        button_pressed();
    }

    if(b_state==buttonstate::TOGGLE_OFF){
        buttons->isCheckable();
        buttons->setChecked(false);
        button_released();
    }
    if(b_state==buttonstate::TOGGLE_ON){
        buttons->isCheckable();
        buttons->setChecked(true);
        button_pressed();
    }

}

void button::button_toggled(bool checked){

    if(checked){
        button_pressed();
        std::cout<<"button toggled true"<<std::endl;
    }
    if(!checked){
        button_released();
        std::cout<<"button toggled false"<<std::endl;
    }
}

void button::button_pressed(){

    buttons->setStyleSheet(style_pressed);
    buttons->setIcon(icon_pressed);
    buttons->setIconSize(icon_size_pressed);
    if(live_mode){
        if(t==haltype::HAL_BIT_IN){
            value_pressed=*pin_bit->pin;
        }
        if(t==haltype::HAL_BIT_OUT){
            *pin_bit->pin=value_pressed.toInt();
        }
        if(t==haltype::HAL_BIT_PARAM_RW){
            param_bit->pin=value_pressed.toInt();
        }
        if(t==haltype::HAL_FLOAT_IN){
            value_pressed=*pin_float->pin;
        }
        if(t==haltype::HAL_FLOAT_OUT){
            *pin_float->pin=value_pressed.toFloat();
        }
        if(t==haltype::HAL_FLOAT_PARAM_RW){
            param_float->pin=value_pressed.toFloat();
        }
        if(t==haltype::HAL_S32_IN){
            value_pressed=*pin_s32->pin;
        }
        if(t==haltype::HAL_S32_OUT){
            *pin_s32->pin=value_pressed.toInt();
        }
        if(t==haltype::HAL_S32_PARAM_RW){
            param_s32->pin=value_pressed.toInt();
        }
        if(t==haltype::HAL_U32_IN){
            value_pressed=*pin_u32->pin;
        }
        if(t==haltype::HAL_U32_OUT){
            *pin_u32->pin=value_pressed.toUInt();
        }
        if(t==haltype::HAL_U32_PARAM_RW){
            param_u32->pin=value_pressed.toUInt();
        }
        if(t==haltype::HAL_PORT_IN){
            std::cout<<"not supported here"<<std::endl;
        }
        if(t==haltype::HAL_PORT_OUT){
            std::cout<<"not supported here"<<std::endl;
        }
        if(t==haltype::HAL_COMP){
            std::cout<<"not supported here"<<std::endl;
        }
    }
    std::cout<<"button pressed value:"<<value_pressed.toStdString()<<std::endl;
}

void button::button_released(){

    buttons->setStyleSheet(style_released);
    buttons->setIcon(icon_released);
    buttons->setIconSize(icon_size_released);
    if(live_mode){
        if(t==haltype::HAL_BIT_IN){
            value_released=*pin_bit->pin;
        }
        if(t==haltype::HAL_BIT_OUT){
            *pin_bit->pin=value_released.toInt();
        }
        if(t==haltype::HAL_BIT_PARAM_RW){
            param_bit->pin=value_released.toInt();
        }
        if(t==haltype::HAL_FLOAT_IN){
            value_released=*pin_float->pin;
        }
        if(t==haltype::HAL_FLOAT_OUT){
            *pin_float->pin=value_released.toFloat();
        }
        if(t==haltype::HAL_FLOAT_PARAM_RW){
            param_float->pin=value_released.toFloat();
        }
        if(t==haltype::HAL_S32_IN){
            value_released=*pin_s32->pin;
        }
        if(t==haltype::HAL_S32_OUT){
            *pin_s32->pin=value_released.toInt();
        }
        if(t==haltype::HAL_S32_PARAM_RW){
            param_s32->pin=value_released.toInt();
        }
        if(t==haltype::HAL_U32_IN){
            value_released=*pin_u32->pin;
        }
        if(t==haltype::HAL_U32_OUT){
            *pin_u32->pin=value_released.toUInt();
        }
        if(t==haltype::HAL_U32_PARAM_RW){
            param_u32->pin=value_released.toUInt();
        }
        if(t==haltype::HAL_PORT_IN){
            std::cout<<"not supported here"<<std::endl;
        }
        if(t==haltype::HAL_PORT_OUT){
            std::cout<<"not supported here"<<std::endl;
        }
        if(t==haltype::HAL_COMP){
            std::cout<<"not supported here"<<std::endl;
        }
    }
    std::cout<<"button released value:"<<value_released.toStdString()<<std::endl;
}

