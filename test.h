#include <assert.h>
#include "BMSDataSender.h"

void test()
{
  printf("Check if print on console is successful");
  assert(communicateSensorData()==1);           
}
