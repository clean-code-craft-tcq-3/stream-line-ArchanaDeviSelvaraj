#include<stdio.h>

void readSensorDataFromFile
{ 
    FILE *fp; 
    float temperature,chargerate;
    fp =fopen("SensorData.txt","r");
    if (!fp)
    printf("\n File doesn't exist");
    while (fgets(temperature,chargerate,1000, fp)!=NULL)
    printf("%f","%f",temperature,chargerate);
    fclose(fp); 
 }
