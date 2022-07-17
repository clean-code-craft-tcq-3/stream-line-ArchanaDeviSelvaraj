#include<stdio.h>
#include "BMSDataSender.h"

int readings_count_check=0;

void readSensorDataFromFile(float* temperature, float* chargerate)
{ 
    FILE *fp; 
    float temp_data,chargerate_data;
    fp =fopen("SensorData.txt","r");
    if (!fp)
    {
    printf("\n File doesn't exist");
    }
    else
    {
        for(int index=0; fscanf(fp, "%f %f\n",&temp_data,&chargerate_data)!=EOF; index++)
        {
          *(temperature+index) = temp_data;
          *(chargerate+index) = chargerate_data;
        }
    }
    fclose(fp); 
 }
    
 int printSensorDataToConsole(float* temperature, float* chargerate)
 {
     for(int index=0,index<total_readings_count;index++)
     {
         printf("%f \t %f \n",*(temperature+index),*(chargerate+index));
         readings_count_check++;
     }
     verifyPrintToConsole(readings_count_check);
 }
 
 int verifyPrintToConsole(int readings_count_check)
 {
     if(readings_count_check == total_readings_count)
         return 1;
     else
         return 0;
 }
    
 int main()
 {
     test();
     return 0;
 }
    
         
     
