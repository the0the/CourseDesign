#include "module.h"
#include "bluetooth.h"

#define RCOFFLINE  0x01 /*遥控离线*/
#define WORKNORMAL 0x02 /*正常工作*/

/*
 * P3.6接LED
 */
sbit LED = P3 ^ 6; 


/**********************FUNCTION***********************
 * @brief: 下位机状态显示
 * @param: sta: 下位机状态，RCOFFLINE WORKNORMAL
 * @note: 如果遥控器离线指示LED以1000ms的周期快闪
 *        如果正常工作LED每隔1000ms闪烁两次
 *****************************************************/
static void LED_state(uint8_t sta)
{
    static uint8_t cnt = 0;
    switch (sta)
    {
        case RCOFFLINE:
            LED = cnt % 2;
            break;
        case WORKNORMAL:
            if (cnt == 2 || cnt == 4)
            {
                LED = 1;
            }
            else
            {
                LED = 0;
            }
            break;
        default:
            break;
    }
    
    if (++cnt > 5)
    {
        cnt = 0;
    }
}

void Task_10Hz_1()
{    
}

void Task_10Hz_2()
{
    /* 离线检测计数, 超过1000ms认为离线 */
    if (RCOfflineCheckCnt++ > 10)
    {
        isRCOffline = 1;
    }
}

/*
 * 执行周期500ms
 */
void Task_2Hz()
{
    static uint8_t state = 0;
    
    if (isRCOffline == 1)
    {
        state = RCOFFLINE;
    }
    else
    {
        state = WORKNORMAL;
    }
    
    LED_state(state);
}

void Task_1Hz()
{
}