#ifdef TEST

#include "unity.h"

#include "cmockModule.h"

#include "mock_adc.h"

#include "mock_logger.h"

#include "mock_bar.h"

#include "global.h"


void setUp(void)
{
}

void tearDown(void)
{
}

//Expect Arguments
void test_expect_arg_control(void)
{
	adc_initialize_Expect(3);
    temperature_initialize();
}

//Ignore Arguments
void test_ignore_arg_control(void)
{
	/*
	Varsayılan olarak argüman ihmali tanımlı değil bunun için project.yml dosyasına aşağıdaki kod parçasının
	eklenmesi gerekiyor.
	cmock:
       :mock_prefix: mock_
       :when_no_prototypes: :warn
       :enforce_strict_ordering: TRUE
       :plugins:
          - :ignore
          - :callback
          - :ignore_arg
	*/
	adc_initialize_Expect(4);
	adc_initialize_IgnoreArg_channel();
    temperature_initialize();
}

//Argument passed by Referans
void test_arg_passed_by_referanse_control(void)
{
    adc_config_t expected_config = {0}; 
    expected_config.channel = 3; 
    expected_config.clock_rate = 40000000;
    expected_config.sample_rate = 1000;
    adc_initialize_configuration_Expect(&expected_config); 
    temperature_initialize_with_config();
}

//Argument returned by Referans 
void test_arg_returned_by_referanse_control(void)
{
   adc_config_t mock_config = {0}; 
   mock_config.channel = 3;
   mock_config.clock_rate = 40000000;
   mock_config.sample_rate = 1000;
   adc_get_configuration_Expect(0); 
   adc_get_configuration_IgnoreArg_configuration(); 
   adc_get_configuration_ReturnThruPtr_configuration(&mock_config); 
   TEST_ASSERT_TRUE(is_temperature_configured()); 
}

//String as arguments
void test_str_arg_control(void)
{
    log_message_Expect("temperature module initialized"); 
    temperature_initialize_with_log();
}

//Ignoring function callback
void test_ignore_func_call_control(void)
{
    log_message_Ignore();
    temperature_initialize_with_log();
}

//Array as a Arguments
void test_arr_arg_control(void)
{
	/*
	Varsayılan olarak argüman ihmali tanımlı değil bunun için project.yml dosyasına aşağıdaki kod parçasının
	eklenmesi gerekiyor.
	:cmock:
       :mock_prefix: mock_
       :when_no_prototypes: :warn
       :enforce_strict_ordering: TRUE
       :plugins:
         - :ignore
         - :callback
         - :ignore_arg
         - :array
	*/
	int expected_data[] = {1, 2, 3, 4, 5}; 
    bar_with_int_array_ExpectWithArray(expected_data, 5);
    foo_function_with_array_argument_call();
}

//Using Callback to Take Control
uint8_t mock_adc_get_sample(int call_count) 
{
    return call_count;
}

void test_callback_control(void)
{
	adc_get_sample_StubWithCallback(mock_adc_get_sample); 
    for (int i = 0; i <= 150; i++)
    {
        TEST_ASSERT_FALSE(is_temperature_over_limit()); 
    }
    TEST_ASSERT_TRUE(is_temperature_over_limit()); 
}
#endif // TEST
