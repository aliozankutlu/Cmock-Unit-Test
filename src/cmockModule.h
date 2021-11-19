#ifndef CMOCKMODULE_H
#define CMOCKMODULE_H

#include "global.h"

void temperature_initialize(void);
void temperature_initialize_with_config(void);
void temperature_initialize_with_log (void);
bool is_temperature_configured(void);
void foo_function_with_array_argument_call(void);
bool is_temperature_over_limit(void);

#endif // CMOCKMODULE_H
