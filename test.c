#include <assert.h>
#include "BMSDataSender.h"

int main()
 {
     printf("\nCheck if print on console is successful");
     assert(communicateSensorData()==1);    
     printf("\nTo check verifyPrintToConsole function"); 
     assert(verifyPrintToConsole(50)==1);
     assert(verifyPrintToConsole(0)==0);
     printf("\nTo Verify read and print fucntions");
     float temperature_array[total_readings_count] ={0};
     float chargerate_array[total_readings_count] ={0};
     readSensorDataFromFile(temperature_array,chargerate_array);
     printf("\n Temperature : %f \t Charge rate : %f \n",*(temperature_array+0),*(chargerate_array+0)); 
     float expected_temp_value_1 = *(temperature_array+0);
     float expected_chargerate_value_1 = *(chargerate_array+0);
     assert(expected_temp_value_1 == 10);
     return 0;
 }

