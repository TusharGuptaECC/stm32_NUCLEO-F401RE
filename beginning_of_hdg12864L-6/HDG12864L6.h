#ifndef __HDG12864L6_H
//#define __HDG12864L-6_H
#include<stdint.h>
// cmds
#define display_on 0x0000AF00
#define display_off 0x0000AE00
#define adc_normal 0x0000A000
#define adc_reverse 0x0000A100
#define display_normal 0x0000A600
#define display_reverse 0x0000A700
#define display_all_points 0x0000A500
#define displayAP_normal 0x0000A400
#define bias0 0x0000A200
#define bias1 0x0000A300
#define com_op_mode_nom 0x0000C000
#define com_op_mode_rev 0x0000C800
#define OB 'B'
#define OT 'T'

// global variables
uint32_t record[8][132];

// user defined functions
void writeCmd(uint32_t cmd);
void writeData(uint32_t data);
void glcdInit(void);
void setLocation(uint32_t st_line, uint32_t pg_adrs, uint32_t up_add, uint32_t low_add);
void increment(void);
void reset(void);
void staticIndicator(void);
void displayDot(uint32_t, uint32_t, int);
void allRecordZero(void);

#endif
