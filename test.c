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
     float output_data[5][2] = {{10,0.10}, {26,0.15}, {22,0.20},{36,0.78},{43,0.10}};
     readSensorDataFromFile(temperature_array,chargerate_array);
 
     int count= 0, index= 0;
     for(index=0;index<4;index++)
     {
       assert(temperature_array[count] == output_data[index][0]);
       assert(chargerate_array[count] == output_data[index][1]);
       count++;
     }
   
     int printcheck = printSensorDataToConsole(temperature_array,chargerate_array);
     assert(printcheck == 1);
     
     return 0;
 }

