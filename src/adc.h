/*
 * adc.h
 *
 *  Created on: Aug 17, 2021
 *      Author: User
 */

#ifndef ADC_H_
#define ADC_H_

#include "global.h"

typedef struct 
{
	uint8_t channel;
	uint32_t clock_rate;
	uint32_t sample_rate;
} adc_config_t;

void adc_initialize_configuration(adc_config_t *configuration);
void adc_initialize(uint8_t channel);
void adc_get_configuration (adc_config_t * configuration);
uint8_t adc_get_sample(void);

#endif /* ADC_H_ */
