#include<stdio.h>
#define total_readings_count 50

void readSensorDataFromConsole(float* temperature, float* chargeRate);
float calculateMaxValue(float* sensorParameterName);
float calculateMinValue(float* sensorParameterName);
int printCalulatedDataToConsole(float* sensorParameterName,float maxValue, float minValue, float movingAverage);
int displayProcessedData(float* Temperature, float* chargeRate);
