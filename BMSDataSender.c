#include<stdio.h>

void readSensorDataFromFile
{ 
    FILE *fp; 
    float temperature,chargerate;
    fp =fopen("SensorData.txt","r");
    if (!fp)// checking for error
    return 1;
    while (fgets(temperature,chargerate,1000, fp)!=NULL)// reading file content
    printf("%f","%f",temperature,chargerate);
    fclose(fp); // closing file
    return 0;
	}
