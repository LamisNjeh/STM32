#include "mbed.h"
#include "BluetoothSerial.h"
#include "SeeedStudioShieldBot.h"

#include "AMT22.h"


#define AMT22_NOP       0x00
#define AMT22_RESET     0x60
#define AMT22_ZERO      0x70

#define RES12           12
#define RES14           14


void setCSLine (GPIO_TypeDef* encoderPort, uint16_t encoderPin, GPIO_PinState csLine)
{
    HAL_GPIO_WritePin(encoderPort, encoderPin, csLine);
}

uint8_t spiWriteRead(SPI_HandleTypeDef *hspi, uint8_t sendByte, GPIO_TypeDef* encoderPort, uint16_t encoderPin, uint8_t releaseLine, TIM_HandleTypeDef *timer)
{
   
  uint8_t data;

  
  setCSLine(encoderPort, encoderPin , GPIO_PIN_RESET);

  
  delay(timer, 3);
  
  HAL_SPI_TransmitReceive(hspi, &sendByte, &data, 1, 10);

  
  delay(timer, 3);
  setCSLine(encoderPort, encoderPin, releaseLine); 

  return data;
}

uint16_t getPositionSPI(SPI_HandleTypeDef *hspi, GPIO_TypeDef* encoderPort, uint16_t encoderPin, uint8_t resolution, TIM_HandleTypeDef *timer)
{
  uint16_t currentPosition;      
  uint8_t binaryArray[16];        

  currentPosition = spiWriteRead(hspi, AMT22_NOP, encoderPort, encoderPin, 0, timer) << 8;


  delay(timer, 3);

  currentPosition |= spiWriteRead(hspi, AMT22_NOP, encoderPort, encoderPin, 1, timer);

  
  for(int i = 0; i < 16; i++) binaryArray[i] = (0x01) & (currentPosition >> (i));

  if ((binaryArray[15] == !(binaryArray[13] ^ binaryArray[11] ^ binaryArray[9] ^ binaryArray[7] ^ binaryArray[5] ^ binaryArray[3] ^ binaryArray[1]))
          && (binaryArray[14] == !(binaryArray[12] ^ binaryArray[10] ^ binaryArray[8] ^ binaryArray[6] ^ binaryArray[4] ^ binaryArray[2] ^ binaryArray[0])))
    {
      currentPosition &= 0x3FFF;
    }
  else
  {
    currentPosition = 0xFFFF; 
  }

 
  if ((resolution == RES12) && (currentPosition != 0xFFFF)) currentPosition = currentPosition >> 2;
  return currentPosition;
}

void setZeroSPI(SPI_HandleTypeDef *hspi, GPIO_TypeDef* encoderPort, uint16_t encoderPin, TIM_HandleTypeDef *timer)
{
  spiWriteRead(&hspi,AMT22_NOP, encoderPort, encoderPin, 0, timer);

  delay(timer, 3);

  spiWriteRead(&hspi, AMT22_ZERO, encoderPort, encoderPin, 1, timer);


  delay(timer, 250);
}

void resetAMT22(SPI_HandleTypeDef *hspi, GPIO_TypeDef* encoderPort, uint16_t encoderPin, TIM_HandleTypeDef *timer)
{
  spiWriteRead(&hspi, AMT22_NOP, encoderPort, encoderPin, 0, timer);


  delay(timer, 3);

  spiWriteRead(&hspi, AMT22_RESET, encoderPort, encoderPin, 1, timer);

  delay(timer, 250);
}

void delay(TIM_HandleTypeDef *timer, uint32_t delayTime){
    uint32_t startTime = __HAL_TIM_GET_COUNTER(timer);  
    uint32_t passedTime  = 0;

    while (passedTime<delayTime){
        passedTime = __HAL_TIM_GET_COUNTER(timer) - startTime;
        if (passedTime<0){
            passedTime +=timer->Init.Period;
        }
    }
}
