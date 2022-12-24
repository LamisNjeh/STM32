#include <Adafruit_ADS1X15.h>


Adafruit_ADS1015 ads;     

void setup(void)
{
  Serial.begin(9600);
  Serial.println("Hello!");

  Serial.println("Single-ended readings from AIN0 with >3.0V comparator");
  Serial.println("ADC Range: +/- 6.144V (1 bit = 3mV/ADS1015, 0.1875mV/ADS1115)");
  Serial.println("Comparator Threshold: 1000 (3.000V)");


  if (!ads.begin()) {
    Serial.println("Failed to initialize ADS.");
    while (1);
  }
 
  ads.startComparator_SingleEnded(0, 1000);
}

void loop(void)
{
  int16_t adc0;


  adc0 = ads.getLastConversionResults();
  Serial.print("AIN0: "); Serial.println(adc0);

  delay(100);
}
