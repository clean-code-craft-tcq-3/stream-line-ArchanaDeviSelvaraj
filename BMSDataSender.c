#include<stdio.h>

void readSensorDataFromFile
{ 
    FILE *fp; 
    float temperature,chargerate;
    fp =fopen("SensorData.txt","r");
    if (!fp)
    return 1;
    while (fgets(temperature,chargerate,1000, fp)!=NULL)// reading file content
    printf("%f","%f",temperature,chargerate);
    fclose(fp); 
    return 0;
 }
