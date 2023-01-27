#ifndef SAVEFILE_H
#define SAVEFILE_H

#include "n64types.h"
#include "modules.h"

enum PFS_ERR {
    PFS_OK = 0,
    PFS_ERR_NOPACK = 1,
    PFS_ERR_NEW_PACK = 2,
    PFS_ERR_INCONSISTENT = 3,
    PFS_ERR_CONTRFAIL = 4,
    PFS_ERR_INVALID = 5,
    PFS_ERR_BAD_DATA = 6,
    PFS_DATA_FULL = 7,
    PFS_DIR_FULL = 8,
    PFS_ERR_EXIST = 9,
    PFS_ERR_ID_FATAL = 10,
    PFS_ERR_DEVICE = 11,
    PFS_ERR_NO_GBCART = 12,
    PFS_ERR_NEW_GBCART = 13
};

enum save_data_copy_direction {
    GAME_TO_CPAK,
    CPAK_TO_GAME,
    CPAK_TO_BACKUP,
    BACKUP_TO_CPAK
};

enum saveFile_additional_settings {
    GAME_WAS_SAVED_MID_PLAY = 1,
    EASY = 16,
    NORMAL = 32,
    HARD = 64,
    HARD_MODE = 256,
    HAVE_REINHARDT_ALT_COSTUME = 512,
    HAVE_CARRIE_ALT_COSTUME = 1024,
    REINDHART_GOOD_ENDING = 131072,
    CARRIE_GOOD_ENDING = 262144,
    REINDHART_BAD_ENDING = 524288,
    CARRIE_BAD_ENDING = 1048576,
    COSTUME_IS_BEING_USED = 1073741824,
    CAN_EXPLODE_ON_JUMPING = 2147483648
};

enum stage_ID {
    MORI = 0,
    TOU = 1,
    TOUOKUJI = 2,
    NAKANIWA = 3,
    BEKKAN_1F = 4,
    BEKKAN_2F = 5,
    MEIRO_TEIEN = 6,
    CHIKA_KODO = 7,
    CHIKA_SUIRO = 8,
    HONMARU_B1F = 9,
    HONMARU_1F = 10,
    HONMARU_2F = 11,
    HONMARU_3F_MINAMI = 12,
    HONMARU_4F_MINAMI = 13,
    HONMARU_3F_KITA = 14,
    HONMARU_5F = 15,
    SHOKEI_TOU = 16,
    MAHOU_TOU = 17,
    KAGAKU_TOU = 18,
    KETTOU_TOU = 19,
    TURO_TOKEITOU = 20,
    TENSHU = 21,
    ENDING_DUMMY = 22,
    TOKEITOU_NAI = 23,
    DRACULA = 24,
    ROSE = 25,
    BEKKAN_BOSS = 26,
    TOU_TURO = 27,
    ENDING = 28,
    TEST_GRID = 29,
    NONE = 65535
};

typedef struct {
    u32 event_flags[16];
    u32 flags;
    u16 weeks_passed;
    u16 day;
    u16 hour;
    u16 minute;
    u16 seconds;
    u16 milliseconds;
    u32 field8_0x50;
    s16 field9_0x54;
    s16 field10_0x56;
    u16 character;
    u16 life;
    u16 field13_0x5c;       /* Maybe related to the scrapped Magic meter? */
    u16 subweapon;
    u32 money;
    u8 inventory_items_amount[42];
    u8 field22_0x8e;
    u8 field23_0x8f;
    u8 field24_0x90;
    u8 field25_0x91;
    u8 field26_0x92;
    u8 field27_0x93;
    u8 field28_0x94;
    u8 field29_0x95;
    u8 field30_0x96;
    u8 field31_0x97;
    u8 field32_0x98;
    u8 field33_0x99;
    u8 field34_0x9a;
    u8 field35_0x9b;
    u8 field36_0x9c;
    u8 field37_0x9d;
    u8 field38_0x9e;
    u8 field39_0x9f;
    u8 field40_0xa0;
    u8 field41_0xa1;
    u8 field42_0xa2;
    u8 field43_0xa3;
    u32 player_flags;
    u16 health_depletion_rate_while_poisoned;
    u16 current_hour_VAMP;          /* If greater than 0x17, you turn into vampire */
    s16 map_ID;
    s16 map_entrance_ID;
    u8 save_crystal_number;
    u8 field50_0xb1;
    u8 field51_0xb2;
    u8 field52_0xb3;
    u32 time_saved_counter;
    u32 death_counter;
    u8 field55_0xbc;
    u8 field56_0xbd;
    u8 field57_0xbe;
    u8 field58_0xbf;
    u8 field59_0xc0;
    u8 field60_0xc1;
    u8 field61_0xc2;
    u8 field62_0xc3;
    u8 field63_0xc4;
    u8 field64_0xc5;
    u8 field65_0xc6;
    u8 field66_0xc7;
    u8 field67_0xc8;
    u8 field68_0xc9;
    u8 field69_0xca;
    u8 field70_0xcb;
    u8 field71_0xcc;
    u8 field72_0xcd;
    u8 field73_0xce;
    u8 field74_0xcf;
    u8 field75_0xd0;
    u8 field76_0xd1;
    u8 field77_0xd2;
    u8 field78_0xd3;
    u8 field79_0xd4;
    u8 field80_0xd5;
    u8 field81_0xd6;
    u8 field82_0xd7;
    u8 field83_0xd8;
    u8 field84_0xd9;
    u8 field85_0xda;
    u8 field86_0xdb;
    u32 money_spent_on_Renon;
} SaveFileSlotState;

typedef struct {
    SaveFileSlotState main_state;
    SaveFileSlotState beginning_of_stage_state;
    u32 first_checksum;
    u32 second_checksum;
    u8 field4_0x1c8;
    u8 field5_0x1c9;
    u8 field6_0x1ca;
    u8 field7_0x1cb;
    u8 field8_0x1cc;
    u8 field9_0x1cd;
    u8 field10_0x1ce;
    u8 field11_0x1cf;
    u8 field12_0x1d0;
    u8 field13_0x1d1;
    u8 field14_0x1d2;
    u8 field15_0x1d3;
    u8 field16_0x1d4;
    u8 field17_0x1d5;
    u8 field18_0x1d6;
    u8 field19_0x1d7;
    u8 field20_0x1d8;
    u8 field21_0x1d9;
    u8 field22_0x1da;
    u8 field23_0x1db;
    u8 field24_0x1dc;
    u8 field25_0x1dd;
    u8 field26_0x1de;
    u8 field27_0x1df;
    u8 field28_0x1e0;
    u8 field29_0x1e1;
    u8 field30_0x1e2;
    u8 field31_0x1e3;
    u8 field32_0x1e4;
    u8 field33_0x1e5;
    u8 field34_0x1e6;
    u8 field35_0x1e7;
    u8 field36_0x1e8;
    u8 field37_0x1e9;
    u8 field38_0x1ea;
    u8 field39_0x1eb;
    u8 field40_0x1ec;
    u8 field41_0x1ed;
    u8 field42_0x1ee;
    u8 field43_0x1ef;
    u8 field44_0x1f0;
    u8 field45_0x1f1;
    u8 field46_0x1f2;
    u8 field47_0x1f3;
    u8 field48_0x1f4;
    u8 field49_0x1f5;
    u8 field50_0x1f6;
    u8 field51_0x1f7;
    u8 field52_0x1f8;
    u8 field53_0x1f9;
    u8 field54_0x1fa;
    u8 field55_0x1fb;
    u8 field56_0x1fc;
    u8 field57_0x1fd;
    u8 field58_0x1fe;
    u8 field59_0x1ff;
} SaveFileSlot;

#define SAVE_STATE_SIZE sizeof(SaveFileSlotState)
#define SAVE_SLOT_SIZE sizeof(SaveFileSlot)

#endif
