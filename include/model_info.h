#ifndef MODEL_INFO_H
#define MODEL_INFO_H

#include "n64types.h"
#include "math.h"

typedef struct {
    u16 type;
    u16 flags;
    void* field2_0x4;
    u8 field3_0x8;
    u8 field4_0x9;
    u8 field5_0xa;
    u8 field6_0xb;
    void* field7_0xc;		// struct_8
    u8 field8_0x10;
    u8 field9_0x11;
    u8 field10_0x12;
    u8 field11_0x13;
    u32 ambient_color;
    u8 field13_0x18;
    u8 field14_0x19;
    u8 field15_0x1a;
    u8 field16_0x1b;
    u8 field17_0x1c;
    u8 field18_0x1d;
    u8 field19_0x1e;
    u8 field20_0x1f;
    u32 field21_0x20;
    u16 texture;
    u16 color;
    u8 field24_0x28;
    u8 field25_0x29;
    u8 field26_0x2a;
    u8 field27_0x2b;
    u8 field28_0x2c;
    u8 field29_0x2d;
    u8 field30_0x2e;
    u8 field31_0x2f;
    void* a_display_list_ptr;
    u32 display_list_address;
    u8 field34_0x38;
    u8 field35_0x39;
    u8 field36_0x3a;
    u8 field37_0x3b;
    s32 assets_file_ID;
    vec3f position;
    angle model_angle;
    s16 field41_0x52;
    s16 field42_0x54;
    s16 field43_0x56;
    vec3f size;
    u8 field45_0x64;
    u8 field46_0x65;
    u8 field47_0x66;
    u8 field48_0x67;
    u8 field49_0x68;
    u8 field50_0x69;
    u8 field51_0x6a;
    u8 field52_0x6b;
    u8 field53_0x6c;
    u8 field54_0x6d;
    u8 field55_0x6e;
    u8 field56_0x6f;
    u8 field57_0x70;
    u8 field58_0x71;
    u8 field59_0x72;
    u8 field60_0x73;
    u8 field61_0x74;
    u8 field62_0x75;
    u8 field63_0x76;
    u8 field64_0x77;
    u8 field65_0x78;
    u8 field66_0x79;
    u8 field67_0x7a;
    u8 field68_0x7b;
    u8 field69_0x7c;
    u8 field70_0x7d;
    u8 field71_0x7e;
    u8 field72_0x7f;
    u8 field73_0x80;
    u8 field74_0x81;
    u8 field75_0x82;
    u8 field76_0x83;
    u8 field77_0x84;
    u8 field78_0x85;
    u8 field79_0x86;
    u8 field80_0x87;
    u8 field81_0x88;
    u8 field82_0x89;
    u8 field83_0x8a;
    u8 field84_0x8b;
    u8 field85_0x8c;
    u8 field86_0x8d;
    u8 field87_0x8e;
    u8 field88_0x8f;
    u8 field89_0x90;
    u8 field90_0x91;
    u8 field91_0x92;
    u8 field92_0x93;
    u8 field93_0x94;
    u8 field94_0x95;
    u8 field95_0x96;
    u8 field96_0x97;
    u8 field97_0x98;
    u8 field98_0x99;
    u8 field99_0x9a;
    u8 field100_0x9b;
    u8 field101_0x9c;
    u8 field102_0x9d;
    u8 field103_0x9e;
    u8 field104_0x9f;
    u8 field105_0xa0;
    u8 field106_0xa1;
    u8 field107_0xa2;
    u8 field108_0xa3;
    u8 field109_0xa4;
    u8 field110_0xa5;
    u8 field111_0xa6;
    u8 field112_0xa7;
} model_info;

enum model_info_types {
    HUD_ELEMENT = 0x10
};

extern model_info* D_8009B444;
extern model_info* HUD_camera;
extern model_info* modelInfo_createRootNode(u16 param_1, model_info* param_2);

#endif
