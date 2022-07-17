#include <assert.h>
#include "BMSDataSender.h"

void test()
{
  int readings_count_check;
  printf("Check if print on console is successful");
  assert(verifyPrintToConsole(readings_count_check)==1);           
}
