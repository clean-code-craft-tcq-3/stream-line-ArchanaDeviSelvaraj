#define total_readings_count 50

void readSensorDataFromFile(float* temperature, float* chargerate);
int printSensorDataToConsole(float* temperature, float* chargerate);
int verifyPrintToConsole(int readings_count_check);
void test();
