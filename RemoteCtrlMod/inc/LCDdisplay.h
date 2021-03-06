#ifndef __LCD_DISPLAY_H__
#define __LCD_DISPLAY_H__
#include "module.h"

/*
 * 1602LCD温度显示
 * setval: 设定值  actulval: 实际值 范围0~999，拆分成三个整数
 */
extern void LCD_display(uint16_t setval, uint16_t actulval); 

/*
 * 获取温度设定值
 */
extern uint16_t get_setval(void);

/*
 * 如果按键状态发生改变将这个值置1
 * 后续由用户手动清零
 */
extern uint8_t isSetValChanged;

/*
 * 是否重置参考值(最低值)，若重置参考值的按键被按下则改位置1
 * 使用后手动清零
 */
extern uint8_t isResetRefVal;

#endif
