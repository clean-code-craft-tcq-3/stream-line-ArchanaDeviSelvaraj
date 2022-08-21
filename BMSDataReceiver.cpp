#include "BMSDataReceiver.hpp"
//#include "BMSDataSender.h"
#include <iostream>
#include <string.h>
using namespace std;

void readSensorDataFromConsole(float* temperature, float* chargeRate)
{
    /*char line[50];
    cin.getline(line,50);
    for(int index = 0; index < total_readings_count+1; index++)
    {
        char line[100],a[20],b[20],c[20],d[20];
        float num1, num2;
        //scanf("%s",line[index]);
        //cin.getline(line,50);
        //printf("%s\n",line);
        //scanf("%f\t %f",&temperature[index],&chargeRate[index]);
        
        scanf("%s\t %s\t %f\t %s\t %s\t %f",&a,&b,&num1,&c,&d,&num2);
        printf("%s\t %s\t %f\t %s\t %s\t %f\n",a,b,num1,c,d,num2);*/
    string data;
    FILE* consoleOutput;
    const int max_size = 1000;
    char InputData[max_size];
    
    consoleOutput = popen(cmd.c_str(),"r");
    if(consoleOutput)
    {
        while(!feof(consoleOutput))
        {
            if(fgets(InputData,max_size, consoleOutput) != NULL)
            {
                data.append(InputData);
            }
        }
        pclose(stream);
    }
    
    cout<<data;
    
    }
}

float calculateMaxValue(float* sensorParameterName)
{
    float maxValue = sensorParameterName[0];
    for(int index = 0; index < total_readings_count; index++)
    {
        if(maxValue < sensorParameterName[index])
        {
            maxValue = sensorParameterName[index];
        }
    }

    return(maxValue);
}

float calculateMinValue(float* sensorParameterName)
{
    float minValue = sensorParameterName[0];
    for(int index = 0; index < total_readings_count; index++)
    {
        if(minValue > sensorParameterName[index])
        {
            minValue = sensorParameterName[index];
        }
    }
    return(minValue);
}

float calculateMovingAverage(float* sensorParameterName)
{
    float sum = 0;
    float movingAverage = 0;
    for(int index = (total_readings_count - 5); index < total_readings_count; index++)
    {
        sum += sensorParameterName[index];
    }
    movingAverage = sum / 5;
    return(movingAverage);
}

int printCalulatedDataToConsole(float* sensorParameterName,float maxValue, float minValue, float movingAverage)
{
    printf("Data received from sender:");
    for(int index = 0; index < total_readings_count; index++)
    {
        printf("%f\n",sensorParameterName[index]);
    }
    printf("Maximum value = %f\n",maxValue);
    printf("Minimum value = %f\n",minValue);
    printf("Average value = %f\n",movingAverage);
    return(1);
}

void displayProcessedData(float* temperature, float* chargeRate)
{
    readSensorDataFromConsole(temperature,chargeRate);
    printCalulatedDataToConsole(temperature,calculateMaxValue(temperature),calculateMinValue(temperature),calculateMovingAverage(temperature));
    printCalulatedDataToConsole(chargeRate,calculateMaxValue(chargeRate),calculateMinValue(chargeRate),calculateMovingAverage(chargeRate));
}


