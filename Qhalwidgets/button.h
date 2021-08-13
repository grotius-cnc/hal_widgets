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

    Q_PROPERTY(QString property_hal_name READ readname WRITE writename)
    Q_PROPERTY(bool property_hal_live_mode READ read_live_mode WRITE write_live_mode)

    //Q_ENUMS(haltype);
    Q_PROPERTY(haltype property_hal_type READ read_type WRITE write_type)

public:

    enum haltype
    {
        NONE,
        HAL_BIT_OUT,
        HAL_BIT_PARAM_RW
    };
    Q_ENUM(haltype)

    button(QWidget *parent = 0);

    QString name="button_0";
    QString readname();
    void writename(QString property_hal_name);

    bool live_mode=0;
    bool read_live_mode();
    void write_live_mode(bool property_hal_live_mode);

    haltype t;
    haltype read_type();
    void write_type(haltype property_hal_type);

private slots:
    void button_pressed();
    void button_released();

private:
    QGridLayout *layout;
    QPushButton *buttons;

    typedef struct {
        hal_bit_t *pin;
    } bit_data_t;
    bit_data_t *pin_bit;

    typedef struct {
        hal_float_t *pin;
    } float_data_t;

    typedef struct {
        hal_s32_t *pin;
    } s32_data_t;

    typedef struct {
        hal_u32_t *pin;
    } u32_data_t;

    typedef struct {
        hal_port_t *pin;
    } port_data_t;

    //! Params
    typedef struct {
        hal_float_t pin;
    } param_float_data_t;

    typedef struct {
        hal_bit_t pin;
    } param_bit_data_t;
    param_bit_data_t *param_bit;

    typedef struct {
        hal_comp_t *data;
    } comp_data_t;
    comp_data_t comp;
};

#endif // BUTTON_H
