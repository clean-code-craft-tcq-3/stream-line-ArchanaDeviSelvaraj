#include <assert.h>
#include "BMSDataSender.h"

void test()
{
  printf("Check if print on console is successful);
  printSensorDataToConsole(temperature,chargerate);
  assert(verifyPrintToConsole(readings_count_check)==1);           
}