#include<stdio.h>

void readSensorDataFromFile (float* temperature, float* chargerate)
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
      *(temperature+i) = temp_data;
      *(chargerate+i) = chargerate_data;
    }
    fclose(fp); 
 }
