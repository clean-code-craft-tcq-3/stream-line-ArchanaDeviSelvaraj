#include <assert.h>
#include "BMSDataSender.h"

int main()
 {
     printf("\nCheck if print on console is successful");
     assert(communicateSensorData()==1);    
     printf("\nTo check verifyPrintToConsole function"); 
     assert(verifyPrintToConsole(50)==1);
     assert(verifyPrintToConsole(0)==0);
     return 0;
 }

