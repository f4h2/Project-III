// #include "DEV_Config.h"
// #include "Adafruit_TSL2591.h"
// void setup() {
//   Serial.begin(9600);  
//   DEV_ModuleInit();
//   TSL2591_Init();
// }

// void loop() {

//   int lightValue = TSL2591_Read_Lux();
//   Serial.println(lightValue);
//   TSL2591_SET_LuxInterrupt(50,200);
//   delay(1000);  
// }

#include <Adafruit_Sensor.h>
#include "Adafruit_TSL2591.h"

Adafruit_TSL2591 tsl = Adafruit_TSL2591(2591); // pass in a number for the sensor identifier (for your use later)


void setup() {
  Serial.begin(9600);
  //tsl.setGain(TSL2591_GAIN_MED);
  tsl.setGain(TSL2591_GAIN_HIGH);
  tsl.setTiming(TSL2591_INTEGRATIONTIME_300MS);

}

void loop(void)
{
  uint16_t sens;

    sens = tsl.getLuminosity(TSL2591_VISIBLE);
    Serial.println(sens );

    
  delay(500);
}