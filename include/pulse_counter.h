#ifndef pulse_counter_h
#define pulse_counter_h

#ifdef __cplusplus
extern "C"
{
#endif

#include <esp_log.h>
#include <esp_err.h>
#include <driver/pcnt.h>

    void initialize_pulse_counter(
        int gpio_pin,
        int16_t Counter_h_lim);
    int16_t get_counter_value();

#ifdef __cplusplus
}
#endif
#endif