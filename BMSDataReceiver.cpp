#include "BMSDataReceiver.hpp"
//#include "BMSDataSender.h"
#include <iostream>
#include <string.h>
//#include <bits/stdc++.h>
using namespace std;

//char line_input[60] = {};  
void readSensorDataFromConsole(float* temperature, float* chargeRate)
{
    int numberCount = 0;
    for(int index1 = 0; index1 <= total_readings_count*2; index1++)
    {
        //char line[100],a[20],b[20],c[20],d[20],e[20];
        //float num1, num2;
        //scanf("%s",line[index]);
        //cin.getline(line,50);
        //printf("%s\n",line);
        //scanf("%f\t %f",&temperature[index],&chargeRate[index]);
        char line_input[60] = {};     
        
        cin.getline(line_input,60);
        cout<<line_input<<endl;
       
        char Temperature_Trial[9] = {};
        char SOC_Trial[9] = {};
        
        if( strchr(line_input,':') != NULL)
        {   
            int index=0;
            for(int i=15 ; i<24; i++)
            {
                Temperature_Trial[index] =  line_input[i];
                index++;
            }
            //cout<<Temperature_Trial<<endl;
            //cout<<numberCount<<" "<<stof(Temperature_Trial)<<" ";
            //string temp_string(Temperature_Trial);
            //cout<<temp_string<<endl;
            temperature[numberCount] = stof(Temperature_Trial);
            cout<<temperature[numberCount]<<endl;
            
            index=0;
            for(int i=41 ; i<51; i++)
            {
                SOC_Trial[index] =  line_input[i];
                index++;
            }
            //cout<<SOC_Trial<<endl;;
            //cout<<stof(SOC_Trial)<<endl;
            chargeRate[numberCount] = stof(SOC_Trial);
            cout<<chargeRate[numberCount]<<endl;
        
        
        //string SOC_string(SOC_Trial);
        //cout<<SOC_string<<endl;
        //float temp_Temperature = stof(temp_string);
        //float temp_chargeRate = stof(SOC_string);
        
        /*
        temperature[numberCount] = temp_Temperature;
        cout<<numberCount<<endl<<temperature[numberCount]<<endl;
        chargeRate[numberCount] = temp_chargeRate;
        cout<<chargeRate[numberCount]<<endl;
        */
        numberCount++;
        }
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


