#ifndef CV64_H
#define CV64_H

#include "n64types.h"
#include "controller.h"
#include "DMAMgr.h"
#include "math.h"
#include "menuButton.h"
#include "model_info.h"
#include "modules.h"
#include "saveFile.h"
#include "textbox.h"
#include "unknown_struct.h"
#include "utils.h"

enum gameState_ID {
    KONAMI_LOGO = 1,
    GAMEPLAY = 2,
    GAME_OVER = 3,
    STAGE_SELECT = 4,
    INTRO_CUTSCENE = 5,
    TITLE_SCREEN = 6,
    DATA_MENU = 7,
    OPTIONS_MENU = 8,
    TITLE_SCREEN_DEMO = 9,
    GAMENOTE_DELETE = 10,
    CREDITS = 11
};

enum fade_flags_enum {
    FADE_IN = 0x4000,
    FADE_OUT = 0x8000
};

extern f32 D_8018AEC8;
extern s16 D_801CC000;
extern s32 func_80000FB4(void* data, u32 size);
extern u32 fade_isFading();
extern void D_801365EC(void*, s32, s32, s32, f32, f32, s32);
extern void fade_setSettings(u16 fade_flags, u16 fade_time, u8 R, u8 G, u8 B);
extern void FUN_80000c28(s32 param_1, s16* param_2, s32 param_3, s16 param_4);
extern u32 FUN_8000f280(u32 file_ID);
extern void FUN_8000219c(void* param_1, s32 param_2, s32 param_3, u32 param_4);
extern void* FUN_80000d80(s32 param_1, s32 param_2);
extern void GameStateMgr_changeGameState(u32 game_state);
extern void func_80000C78(s32 param_1);

#endif
