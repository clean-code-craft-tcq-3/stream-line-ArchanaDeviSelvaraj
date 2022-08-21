#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "BMSDataReceiver.hpp"
#include "BMSDataSender.h"

TEST_CASE("Tests to check whether sensor data is read from console and also to check whether correct Max, Min and SMA values of sensor parameters are printed on console") 
{
  float Temperature[total_readings_count] = {0};
  float ChargeRate[total_readings_count] = {0};
  displayProcessedData(&Temperature[0], &ChargeRate[0]);
  float expectedOutput[2][2] = {{10,0.1}, {26,0.15}};
  printf("-----------------------------------------------");
  printf("%f %f",Temperature[0],ChargeRate[0]);
  for(int index = 0; index < 2; index++)
  {
    REQUIRE(Temperature[index] == expectedOutput[index][0]);
    REQUIRE(ChargeRate[index] == expectedOutput[index][1]);
  }
/*}

TEST_CASE("Check minimum, maximum and moving average of temperature and chargeRate")
{
  float Temperature[readings_count] = {0};
  float ChargeRate[readings_count] = {0};
  readSensorDataFromConsole(&Temperature, &ChargeRate);*/
  float observedMaxValue, observedMinValue, observedSMAValue, expectedMaxValue, expectedMinValue, expectedSMAValue;
  expectedMaxValue = 45;
  expectedMinValue = 0;
  expectedSMAValue = 24;
  observedMaxValue = calculateMaxValue(&Temperature[0]);
  observedMinValue = calculateMinValue(&Temperature[0]);
  observedSMAValue = calculateMovingAverage(&Temperature[0]);
  REQUIRE(observedMaxValue == expectedMaxValue);
  REQUIRE(observedMinValue == expectedMinValue);
  REQUIRE(observedSMAValue == expectedSMAValue);

  REQUIRE(printCalulatedDataToConsole(&Temperature[0],45,0,18) == 1);  

  expectedMaxValue = 0.79;
  expectedMinValue = 0.00;
  expectedSMAValue = 0.3248;
  observedMaxValue = calculateMaxValue(&ChargeRate[0]);
  observedMinValue = calculateMinValue(&ChargeRate[0]);
  observedSMAValue = calculateMovingAverage(&ChargeRate[0]);
  REQUIRE(observedMaxValue == expectedMaxValue);
  REQUIRE(observedMinValue == expectedMinValue);
  REQUIRE(observedSMAValue == expectedSMAValue);

  REQUIRE(printCalulatedDataToConsole(&ChargeRate[0],0.79,0.00,0.81) == 1);
}
