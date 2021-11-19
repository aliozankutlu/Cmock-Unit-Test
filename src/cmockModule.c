#include "global.h"

void temperature_initialize(void)
{
	adc_initialize(3);
}

void temperature_initialize_with_config(void)
{
	adc_config_t config = {0};
    config.channel = 3;
    config.clock_rate = 40000000;
    config.sample_rate = 1000;
    adc_initialize_configuration(&config);
}

bool is_temperature_configured(void)
{
    adc_config_t config = {0};
    adc_get_configuration(&config);
    return (config.channel == 3)
    && (config.clock_rate == 40000000)
    && (config.sample_rate == 1000);
}

void temperature_initialize_with_log (void)
{
    log_message("temperature module initialized"); 
}

void foo_function_with_array_argument_call(void)
{
    int luggage_code[5] = {1, 2, 3, 4, 5};
    bar_with_int_array(luggage_code);
}

bool is_temperature_over_limit(void)
{
	if(adc_get_sample() > 150)
	{
		return 1;
	}
	return 0;
}