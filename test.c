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
     printSensorDataToConsole(temperature_array,chargerate_array);
     printf("\n value %f,*(temperature_array+0)");
     printf("\n value %f,*(chargerate_array+0)");       
     //assert(*(temperature+0)== 10);
     //assert(*(chargerate+0)== 0.100000);
     return 0;
 }

