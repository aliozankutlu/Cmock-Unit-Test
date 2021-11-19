#include "src/global.h"
#include "build/test/mocks/mock_bar.h"
#include "build/test/mocks/mock_logger.h"
#include "build/test/mocks/mock_adc.h"
#include "src/cmockModule.h"
#include "C:/Ruby27-x64/lib/ruby/gems/2.7.0/gems/ceedling-0.31.0/vendor/unity/src/unity.h"


















void setUp(void)

{

}



void tearDown(void)

{

}





void test_expect_arg_control(void)

{

 adc_initialize_CMockExpect(27, 3);

    temperature_initialize();

}





void test_ignore_arg_control(void)

{

 adc_initialize_CMockExpect(46, 4);

 adc_initialize_CMockIgnoreArg_channel(47);

    temperature_initialize();

}





void test_arg_passed_by_referanse_control(void)

{

    adc_config_t expected_config = {0};

    expected_config.channel = 3;

    expected_config.clock_rate = 40000000;

    expected_config.sample_rate = 1000;

    adc_initialize_configuration_CMockExpect(58, &expected_config);

    temperature_initialize_with_config();

}





void test_arg_returned_by_referanse_control(void)

{

   adc_config_t mock_config = {0};

   mock_config.channel = 3;

   mock_config.clock_rate = 40000000;

   mock_config.sample_rate = 1000;

   adc_get_configuration_CMockExpect(69, 0);

   adc_get_configuration_CMockIgnoreArg_configuration(70);

   adc_get_configuration_CMockReturnMemThruPtr_configuration(71, &mock_config, sizeof(adc_config_t));

   do {if ((is_temperature_configured())) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(72)));}} while(0);

}





void test_str_arg_control(void)

{

    log_message_CMockExpect(78, "temperature module initialized");

    temperature_initialize_with_log();

}





void test_ignore_func_call_control(void)

{

    log_message_CMockIgnore();

    temperature_initialize_with_log();

}





void test_arr_arg_control(void)

{

 int expected_data[] = {1, 2, 3, 4, 5};

    bar_with_int_array_CMockExpectWithArray(106, expected_data, 5);

    foo_function_with_array_argument_call();

}





uint8_t mock_adc_get_sample(int call_count)

{

    return call_count;

}



void test_callback_control(void)

{

 adc_get_sample_Stub(mock_adc_get_sample);

    for (int i = 0; i <= 150; i++)

    {

        do {if (!(is_temperature_over_limit())) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(121)));}} while(0);

    }

    do {if ((is_temperature_over_limit())) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(123)));}} while(0);

}
