#ifndef COMPONENT_H
#define COMPONENT_H

#include <QWidget>
#include <QGridLayout>

#ifndef ULAPI
#define ULAPI
#endif

#include "rtapi.h"		/* RTAPI realtime OS API */
#include "hal.h"		/* HAL public API decls */
#include "hal_priv.h"   /* HAL private decls */

class component : public QWidget
{
    Q_OBJECT

public:
    component(QWidget *parent = 0);

private:
    QGridLayout *layout;

    typedef struct {
        hal_bit_t *pin;
    } bit_data_t;

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

    typedef struct {
        hal_float_t pin;
    } param_float_data_t;

    typedef struct {
        hal_bit_t pin;
    } param_bit_data_t;

    typedef struct {
        hal_comp_t *data;
    } comp_data_t;
    comp_data_t comp;
};

#endif // COMPONENT_H
