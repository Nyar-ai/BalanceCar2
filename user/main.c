#include "stm32f10x.h"
#include "Timer.h"
#include "MPU6050.h"
#include "OLED.h"
#include "math.h"
#include "Angle.h"
#include "Serial.h"
int16_t AX, AY, AZ, GX, GY, GZ;
ANGLE angle;
ANGLE angle2;

int main(void)
{   
    Serial_Init();

    Timer_Init();
    OLED_Init();
    MPU6050_Init();
    
    OLED_ShowString(1, 1, "Angle:");
    
    while(1)
    {   OLED_ShowSignedNum(1,6,angle,5);
        printf("[plot,%f]",angle);
    }
}

void TIM2_IRQHandler(void)
{
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
    {	
        // 中断中只读取数据和设置标志

        angle=Get_angle(20000);
        
        
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
    }
}
