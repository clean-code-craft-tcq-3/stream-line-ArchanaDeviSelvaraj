#include <assert.h>
#include "BMSDataSender.h"

int main()
 {
     test();
     return 0;
 }

void test()
{
  printf("Check if print on console is successful");
  assert(communicateSensorData()==1);           
}
