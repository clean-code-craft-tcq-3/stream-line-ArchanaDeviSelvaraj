#include "BMSDataReceiver.hpp"
//#include "BMSDataSender.h"

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


