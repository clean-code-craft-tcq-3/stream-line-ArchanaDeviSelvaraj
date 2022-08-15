#include "BMSDataReceiver.hpp"
#include "BMSDataSender.h"
#include<iostream.h>

void readSensorDataFromConsole(float* temperature, float* chargeRate)
{
    for(int index = 0; index < total_readings_count; index++)
    {
        scanf("%f\t %f",&temperature[index],&chargeRate[index]);
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

flaot calculateMovingAverage(float* sensorParameterName)
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
    std::cout<<"Data received from sender:"<<endl;
    for(int index = 0; index < total_readings_count; index++)
    {
        std::cout<<sensorParameterName[index]<<endl;
    }
    cout<<"Maximum value = "<<maxValue<<endl;
    cout<<"Minimum value = "<<minValue<<endl;
    cout<<"Average value = "<<movingAverage<<endl;
    return(1);
}

int displayProcessedData(int readings_count_check)
{
    readSensorDataFromConsole(temperature,chargeRate);
    printCalulatedDataToConsole(temperature,calculateMaxValue(temperature),calculateMinValue(temperature),calculateMovingAverage(temperature));
    printCalulatedDataToConsole(chargeRate,calculateMaxValue(chargeRate),calculateMinValue(chargeRate),calculateMovingAverage(chargeRate));
}


