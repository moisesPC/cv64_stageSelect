#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include "n64types.h"
#include "math.h"

typedef struct {
    u32 flags;
    void* field1_0x4;
    vec2 position;
    u8 field3_0x10;
    u8 field4_0x11;
    u8 field5_0x12;
    u8 field6_0x13;
    u8 field7_0x14;
    u8 field8_0x15;
    u8 field9_0x16;
    u8 field10_0x17;
    u8 field11_0x18;
    u8 field12_0x19;
    u8 field13_0x1a;
    u8 field14_0x1b;
    u8 field15_0x1c;
    u8 field16_0x1d;
    u8 field17_0x1e;
    u8 field18_0x1f;
    u8 field19_0x20;
    u8 field20_0x21;
    u8 field21_0x22;
    u8 field22_0x23;
    u8 field23_0x24;
    u8 field24_0x25;
    u8 field25_0x26;
    u8 field26_0x27;
    u8 field27_0x28;
    u8 field28_0x29;
    u8 field29_0x2a;
    u8 field30_0x2b;
    u8 field31_0x2c;
    u8 field32_0x2d;
    u8 field33_0x2e;
    u8 field34_0x2f;
    u8 field35_0x30;
    u8 field36_0x31;
    u8 field37_0x32;
    u8 field38_0x33;
    u8 field39_0x34;
    u8 field40_0x35;
    u8 field41_0x36;
    u8 field42_0x37;
    u8 field43_0x38;
    u8 field44_0x39;
    u8 field45_0x3a;
    u8 field46_0x3b;
    u8 field47_0x3c;
    u8 field48_0x3d;
    u8 field49_0x3e;
    u8 field50_0x3f;
    f32 field51_0x40;
} menuButton;

enum menuButton_flags {
    PRESSED_DOWN = 0xC000
};

extern menuButton* menuButton_create(void* param_1, void* param_2, u32 flags, f32 param_4, f32 param_5, f32 param_6, f32 param_7, f32 param_8, f32 param_9);
extern s32 menuButton_selectNextOption(s32* option, s16* param_2, s16 option_max);

#endif
