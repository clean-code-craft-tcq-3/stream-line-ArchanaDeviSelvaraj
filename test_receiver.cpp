#include <assert.h>
#include "BMSDataReceiver.hpp"

TEST_CASE("Sensor data read from console corresctly")
{
  float Temperature[readings_count] = {0};
  float ChargeRate[readings_count] = {0};
  displayProcessedData(&Temperature[0], &ChargeRate[0]);
  float expectedOutput[3][2] = {{10,0.10}, {26,0.15}, {26,0.15}};
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
  expectedMaxValue = 45;
  expectedMinValue = 0;
  expectedSMAValue = 18;
  observedMaxValue = calculateMaxValue(&Temperature[0]);
  observedMinValue = calculateMinValue(&Temperature[0]);
  observedSMAValue = calculateMovingAverage(&Temperature[0]);
  REQUIRE(observedMaxValue == expectedMaxValue);
  REQUIRE(observedMinValue == expectedMinValue);
  REQUIRE(observedSMAValue == expectedSMAValue);

  REQUIRE(printCalulatedDataToConsole(&Temperature[0],45,0,18) == 1);  

  expectedMaxValue = 0.79;
  expectedMinValue = 0.00;
  expectedSMAValue = 0.81;
  observedMaxValue = calculateMaxValue(&ChargeRate[0]);
  observedMinValue = calculateMinValue(&ChargeRate[0]);
  observedSMAValue = calculateMovingAverage(&ChargeRate[0]);
  REQUIRE(observedMaxValue == expectedMaxValue);
  REQUIRE(observedMinValue == expectedMinValue);
  REQUIRE(observedSMAValue == expectedSMAValue);

  REQUIRE(printCalulatedDataToConsole(&ChargeRate[0],0.79,0.00,0.81) == 1);
}