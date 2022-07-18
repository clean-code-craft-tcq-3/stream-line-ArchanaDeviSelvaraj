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
     float temperature[total_readings_count] ={0};
     float chargerate[total_readings_count] ={0};
     readSensorDataFromFile(temperature,chargerate);
     printSensorDataToConsole(temperature, chargerate);
     printf("\n value %f,*(temperature+0)");
     printf("\n value %f,*(chargerate+0)");       
     //assert(*(temperature+0)== 10);
     //assert(*(chargerate+0)== 0.100000);
     return 0;
 }

