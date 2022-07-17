#include <assert.h>
#include "BMSDataSender.h"

int main()
 {
     printf("Check if print on console is successful");
     assert(communicateSensorData()==1);    
     return 0;
 }

