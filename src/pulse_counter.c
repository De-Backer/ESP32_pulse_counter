#include "pulse_counter.h"

static const char *TAG = "pulse_counter";

void initialize_pulse_counter(
    int gpio_pin,
    int16_t Counter_h_lim)
{
    pcnt_config_t config_pcnt_0 = {
        .pulse_gpio_num = gpio_pin,
        .ctrl_gpio_num = PCNT_PIN_NOT_USED,
        .lctrl_mode = PCNT_MODE_KEEP,
        .hctrl_mode = PCNT_MODE_KEEP,
        .pos_mode = PCNT_COUNT_DIS,
        .neg_mode = PCNT_COUNT_INC,
        .counter_h_lim = Counter_h_lim,
        .counter_l_lim = -1,
        .unit = PCNT_UNIT_0,
        .channel = PCNT_CHANNEL_0,
    };
    ESP_LOGI(TAG, "Calling unit_config: ");
    ESP_ERROR_CHECK(pcnt_unit_config(&config_pcnt_0));
    ESP_ERROR_CHECK(pcnt_set_filter_value(PCNT_UNIT_0, 1022));
    ESP_ERROR_CHECK(pcnt_filter_enable(PCNT_UNIT_0));
    /* Initialize PCNT's counter */
    ESP_ERROR_CHECK(pcnt_counter_pause(PCNT_UNIT_0));
    ESP_ERROR_CHECK(pcnt_counter_clear(PCNT_UNIT_0));
    /* Everything is set up, now go to counting */
    ESP_ERROR_CHECK(pcnt_counter_resume(PCNT_UNIT_0));
    ESP_LOGI(TAG, "counter Initialize");
}

int16_t get_counter_value()
{
    int16_t counter_value = 0;
    ESP_ERROR_CHECK(pcnt_get_counter_value(PCNT_UNIT_0, &counter_value));
    //ESP_LOGI(TAG, "counter value : %d", counter_value);
    return counter_value;
}