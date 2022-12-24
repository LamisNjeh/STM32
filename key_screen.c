#include "mbed.h"
#include "BluetoothSerial.h"
#include "SeeedStudioShieldBot.h"


#include "main.h"
#include "../ECUAL/KEYPAD/KEYPAD.h"
#include "../ECUAL/LCD16x2/LCD16x2.h"
 
#define KEY_1       0
#define KEY_2       1
#define KEY_3       2
#define KEY_F1      3
#define KEY_4       4
#define KEY_5       5
#define KEY_6       6
#define KEY_F2      7
#define KEY_7       8
#define KEY_8       9
#define KEY_9       10
#define KEY_F3      11
#define KEY_A       12
#define KEY_0       13
#define KEY_H       14
#define KEY_F4      15
 

uint8_t gu8_KeyStatesArr[KEYS] = {0};
uint8_t SysTicks = 0;
 
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
void SysTick_CallBack(void);
void Display_Handler(void);
 
int main(void)
{
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    KEYPAD_Init(0, gu8_KeyStatesArr);
    LCD_Init();
    LCD_Clear();
    LCD_Set_Cursor(1, 1);
 
    while (1)
    {
        Display_Handler();
        HAL_Delay(10);
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
 
void Display_Handler(void)
{
    if(gu8_KeyStatesArr[KEY_1] == KEY_PRESSED)
    {
    LCD_Write_Char('1');
    while(gu8_KeyStatesArr[KEY_1] == KEY_PRESSED);
    }
    if(gu8_KeyStatesArr[KEY_2] == KEY_PRESSED)
    {
    LCD_Write_Char('2');
    while(gu8_KeyStatesArr[KEY_2] == KEY_PRESSED);
    }
    if(gu8_KeyStatesArr[KEY_3] == KEY_PRESSED)
    {
    LCD_Write_Char('3');
    while(gu8_KeyStatesArr[KEY_3] == KEY_PRESSED);
    }
    if(gu8_KeyStatesArr[KEY_4] == KEY_PRESSED)
    {
    LCD_Write_Char('4');
    while(gu8_KeyStatesArr[KEY_4] == KEY_PRESSED);
    }
    if(gu8_KeyStatesArr[KEY_5] == KEY_PRESSED)
    {
    LCD_Write_Char('5');
    while(gu8_KeyStatesArr[KEY_5] == KEY_PRESSED);
    }
    if(gu8_KeyStatesArr[KEY_6] == KEY_PRESSED)
    {
    LCD_Write_Char('6');
    while(gu8_KeyStatesArr[KEY_6] == KEY_PRESSED);
    }
    if(gu8_KeyStatesArr[KEY_7] == KEY_PRESSED)
    {
    LCD_Write_Char('7');
    while(gu8_KeyStatesArr[KEY_7] == KEY_PRESSED);
    }
    if(gu8_KeyStatesArr[KEY_8] == KEY_PRESSED)
    {
    LCD_Write_Char('8');
    while(gu8_KeyStatesArr[KEY_8] == KEY_PRESSED);
    }
    if(gu8_KeyStatesArr[KEY_9] == KEY_PRESSED)
    {
    LCD_Write_Char('9');
    while(gu8_KeyStatesArr[KEY_9] == KEY_PRESSED);
    }
    if(gu8_KeyStatesArr[KEY_0] == KEY_PRESSED)
    {
    LCD_Write_Char('0');
    while(gu8_KeyStatesArr[KEY_0] == KEY_PRESSED);
    }
    if(gu8_KeyStatesArr[KEY_A] == KEY_PRESSED)
    {
    LCD_Write_Char('*');
    while(gu8_KeyStatesArr[KEY_A] == KEY_PRESSED);
    }
    if(gu8_KeyStatesArr[KEY_H] == KEY_PRESSED)
    {
    LCD_Write_Char('#');
    while(gu8_KeyStatesArr[KEY_H] == KEY_PRESSED);
    }
    if(gu8_KeyStatesArr[KEY_F1] == KEY_PRESSED)
    {
    LCD_SR();
    while(gu8_KeyStatesArr[KEY_F1] == KEY_PRESSED);
    }
    if(gu8_KeyStatesArr[KEY_F2] == KEY_PRESSED)
    {
    LCD_SL();
    while(gu8_KeyStatesArr[KEY_F2] == KEY_PRESSED);
    }
    if(gu8_KeyStatesArr[KEY_F4] == KEY_PRESSED)
    {
    LCD_Clear();
    while(gu8_KeyStatesArr[KEY_F4] == KEY_PRESSED);
    }
}
