#ifndef BUTTON_H
#define BUTTON_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QMetaType>

#ifndef ULAPI
#define ULAPI
#endif

#include "rtapi.h"		/* RTAPI realtime OS API */
#include "hal.h"		/* HAL public API decls */
#include "hal_priv.h"   /* HAL private decls */

class button : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(buttonstate property_buttonstate READ read_buttonstate WRITE write_buttonstate)


    Q_PROPERTY(QColor property_color_pressed READ read_color_pressed WRITE write_color_pressed)
    Q_PROPERTY(QColor property_color_released READ read_color_released WRITE write_color_released)

    Q_PROPERTY(QIcon property_icon_pressed READ read_icon_pressed WRITE write_icon_pressed);
     Q_PROPERTY(QIcon property_icon_released READ read_icon_released WRITE write_icon_released);

    Q_PROPERTY(QSize property_icon_size_pressed READ read_icon_size_pressed WRITE write_icon_size_pressed);
    Q_PROPERTY(QSize property_icon_size_released READ read_icon_size_released WRITE write_icon_size_released);

    Q_PROPERTY(QString property_hal_name READ read_name WRITE write_name)
    Q_PROPERTY(bool property_hal_live_mode READ read_live_mode WRITE write_live_mode)

    Q_PROPERTY(haltype property_hal_type READ read_type WRITE write_type)

    Q_PROPERTY(QString property_hal_value_pressed READ read_value_pressed WRITE write_value_pressed)
    Q_PROPERTY(QString property_hal_value_released READ read_value_released WRITE write_value_released)

public:

    button(QWidget *parent = 0);

    QString value_pressed="0";
    QString value_released="0";
    QString read_value_pressed();
    QString read_value_released();
    void write_value_pressed(QString property_hal_value_pressed);
    void write_value_released(QString property_hal_value_released);

    QColor color_pressed;
    QColor color_released;
    QString style_pressed;
    QString style_released;
    QColor read_color_pressed();
    void write_color_pressed(QColor property_color_pressed);
    QColor read_color_released();
    void write_color_released(QColor property_color_pressed);

    QIcon icon_pressed;
    QIcon read_icon_pressed();
    void write_icon_pressed(QIcon property_icon_pressed);
    QIcon icon_released;
    QIcon read_icon_released();
    void write_icon_released(QIcon property_icon_released);

    QSize icon_size_pressed;
    QSize read_icon_size_pressed();
    void write_icon_size_pressed(QSize property_icon_size_pressed);
    QSize icon_size_released;
    QSize read_icon_size_released();
    void write_icon_size_released(QSize property_icon_size_released);

    enum buttonstate
    {
        NORMAL_OFF=0,
        NORMAL_ON=1,
        TOGGLE_ON=2,
        TOGGLE_OFF=3
    };
    Q_ENUM(buttonstate)
    buttonstate b_state=buttonstate::NORMAL_OFF;
    buttonstate read_buttonstate();
    void write_buttonstate(buttonstate property_buttonstate);

    QString name="button_x";
    QString read_name();
    void write_name(QString property_hal_name);

    bool live_mode=0;
    bool read_live_mode();
    void write_live_mode(bool property_hal_live_mode);

    enum haltype
    {
        NONE=0,
        HAL_BIT_IN=1,
        HAL_BIT_OUT=2,
        HAL_FLOAT_IN=3,
        HAL_FLOAT_OUT=4,
        HAL_S32_IN=5,
        HAL_S32_OUT=6,      // normal int + and - values.
        HAL_U32_IN=7,
        HAL_U32_OUT=8,      // unsigned int, only + values.
        HAL_PORT_IN=9,
        HAL_PORT_OUT=10,
        HAL_COMP=11,
        HAL_BIT_PARAM_RW=12,
        HAL_FLOAT_PARAM_RW=13,
        HAL_U32_PARAM_RW=14,
        HAL_S32_PARAM_RW=15
    };
    Q_ENUM(haltype)
    haltype t;
    haltype read_type();
    void write_type(haltype property_hal_type);

private slots:
    void button_pressed();
    void button_released();
    void button_toggled(bool checked);

private:
    char comp_name[48]="gui";
    QGridLayout *layouts;
    QPushButton *buttons;

    typedef struct {
        hal_bit_t *pin;
    } bit_data_t;
    bit_data_t *pin_bit;

    typedef struct {
        hal_float_t *pin;
    } float_data_t;
    float_data_t *pin_float;

    typedef struct {
        hal_s32_t *pin;
    } s32_data_t;
    s32_data_t *pin_s32;

    typedef struct {
        hal_u32_t *pin;
    } u32_data_t;
    u32_data_t *pin_u32;

    typedef struct {
        hal_port_t *pin;
    } port_data_t;
    port_data_t *pin_port;

    //! Params
    typedef struct {
        hal_float_t pin;
    } float_param_data_t;
    float_param_data_t *param_float;

    typedef struct {
        hal_bit_t pin;
    } bit_param_data_t;
    bit_param_data_t *param_bit;

    typedef struct {
        hal_u32_t pin;
    } u32_param_data_t;
    u32_param_data_t *param_u32;

    typedef struct {
        hal_s32_t pin;
    } s32_param_data_t;
    s32_param_data_t *param_s32;

    typedef struct {
        hal_comp_t data;
    } comp_data_t;
    comp_data_t *pin_comp;
};

#endif // BUTTON_H
