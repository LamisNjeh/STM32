#include "mbed.h"
#include "BluetoothSerial.h"
#include "SeeedStudioShieldBot.h"
#include "KEYPAD.h"
#include "main.h"
#include "../ECUAL/KEYPAD/KEYPAD.h"
#include "../ECUAL/LEDS/LEDS.h"
 
#define LED_BLUE    0
#define LED_YELLOW  1
 
#define KEY_1       0
#define KEY_2       1

#define HAL_GPIO_MODULE_ENABLED
 
#include "stm32f1xx_hal.h"
 
// The Number OF KeyPAD Units To Be Used In The Project
#define KEYPAD_UNITS  1
#define ROWS          4
#define COLS          4
#define KEYS          16
 
#define KEY_PRESSED   1
#define KEY_RELEASED  0
 
typedef struct
{
    GPIO_TypeDef * ROW_GPIO[ROWS];
    uint16_t       ROW_PIN[ROWS];
    GPIO_TypeDef * COL_GPIO[COLS];
    uint16_t       COL_PIN[COLS];
}KEYPAD_CfgType;
 
/*-----[ Prototypes For All Functions ]-----*/
 
void KEYPAD_Init(uint16_t au16_Instance, uint8_t* au8_KeyStates);
void KEYPAD_Scan(uint16_t au16_Instance);



 
const KEYPAD_CfgType KEYPAD_CfgParam[KEYPAD_UNITS] =
{
    // KeyPAD Unit 1 Configurations
    {
        /* ROWs Pins Info */
    {GPIOA, GPIOA, GPIOA, GPIOA},
    {GPIO_PIN_0, GPIO_PIN_1, GPIO_PIN_2, GPIO_PIN_3},
    /* COLs Pins */
    {GPIOA, GPIOA, GPIOA, GPIOA},
    {GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_6, GPIO_PIN_7}
    }
};


uint8_t gu8_KeyStatesArr[KEYS] = {0};
uint8_t SysTicks = 0;
 
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
void SysTick_CallBack(void);
 
int main(void)
{
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    LEDs_Init();
    KEYPAD_Init(0, gu8_KeyStatesArr);
 
    while (1)
    {
        if(gu8_KeyStatesArr[KEY_1] == KEY_PRESSED)
        {
            LED_ON(LED_YELLOW);
        }
        else
        {
            LED_OFF(LED_YELLOW);
        }
        if(gu8_KeyStatesArr[KEY_2] == KEY_PRESSED)
        {
            LED_ON(LED_BLUE);
        }
        else
        {
            LED_OFF(LED_BLUE);
        }
    }
}
 
void SysTick_CallBack(void)
{
    SysTicks++;
    if(SysTicks == 5) // Each 5msec
    {
    KEYPAD_Scan(0);
    SysTicks = 0;
    }
}; 
#define LED_BLUE    0
#define LED_YELLOW  1
 
#define KEY_1       0
#define KEY_2       1
 
uint8_t gu8_KeyStatesArr[KEYS] = {0};
uint8_t SysTicks = 0;
 
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
void SysTick_CallBack(void);
 
int main(void)
{
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    LEDs_Init();
    KEYPAD_Init(0, gu8_KeyStatesArr);
 
    while (1)
    {
        if(gu8_KeyStatesArr[KEY_1] == KEY_PRESSED)
        {
            LED_ON(LED_YELLOW);
        }
        else
        {
            LED_OFF(LED_YELLOW);
        }
        if(gu8_KeyStatesArr[KEY_2] == KEY_PRESSED)
        {
            LED_ON(LED_BLUE);
        }
        else
        {
            LED_OFF(LED_BLUE);
        }
    }
}
void SysTick_CallBack(void)
{
    SysTicks++;
    if(SysTicks == 5) // Each 5msec
    {
    KEYPAD_Scan(0);
    SysTicks = 0;
    }
}
#define LED_BLUE    0
#define LED_YELLOW  1
 
#define KEY_1       0
#define KEY_2       1
 
uint8_t gu8_KeyStatesArr[KEYS] = {0};
uint8_t SysTicks = 0;
 
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
void SysTick_CallBack(void);
 
int main(void)
{
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    LEDs_Init();
    KEYPAD_Init(0, gu8_KeyStatesArr);
 
    while (1)
    {
        if(gu8_KeyStatesArr[KEY_1] == KEY_PRESSED)
        {
            LED_ON(LED_YELLOW);
        }
        else
        {
            LED_OFF(LED_YELLOW);
        }
        if(gu8_KeyStatesArr[KEY_2] == KEY_PRESSED)
        {
            LED_ON(LED_BLUE);
        }
        else
        {
            LED_OFF(LED_BLUE);
        }
    }
}
void SysTick_CallBack(void)
{
    SysTicks++;
    if(SysTicks == 5) // Each 5msec
    {
    KEYPAD_Scan(0);
    SysTicks = 0;
    }
}; 
void SysTick_Handler(void)
{
    HAL_IncTick();
    SysTick_CallBack();
}; 


