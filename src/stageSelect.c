/*
 * File: stageSelect.c
 * Description: Unused Stage Select game state
 * ID = 0x141
 * osMapTLB'd? = No
 * Code execution start = 0x8012A520
 * File Info = -
 */

#include "../include/cv64.h"
#include "../include/stageSelect.h"

// https://decomp.me/scratch/fMxJW
// 0x8012a520
void stageSelect_calc(stageSelect* this) {
    s16 temp;
    
    temp = this->header.functionLoadMgr_ID + 1;
    this->header.functionLoadMgr_ID = temp,        // Comma needed for matching
    this->header.current_function[temp].timer++;
    (*stageSelect_functions[this->header.current_function[temp].function])(this);
    this->header.functionLoadMgr_ID--;
}

// 0x8012a590
void stageSelect_init(stageSelect* this) {
    u32 (*ptr_fade_isFading)() = fade_isFading;
    void (*ptr_fade_setSettings)(u16 fade_flags, u16 fade_time, u8 R, u8 G, u8 B) = fade_setSettings;
    void (*ptr_FUN_80000c28)(s32 param_1, s16* param_2, s32 param_3, s16 param_4) = FUN_80000c28;
    void* (*ptr_FUN_80000d80)(s32 param_1, s32 param_2) = FUN_80000d80;
    void (*ptr_FUN_8000219c)(void* param_1, s32 param_2, s32 param_3, u32 param_4) = FUN_8000219c;
    void (*ptr_goToNextFunc)(s8* functionLoadMgr, s16* functionLoadMgr_ID) = goToNextFunc;

    if ((ptr_fade_isFading() == 0) && (ptr_DMAMgr->DMAChunkMgr != 0)) {
        ptr_fade_setSettings(FADE_IN, 30, 0, 0, 0);
        D_80383AB8.cutscene_flags = 0;
        ptr_FUN_80000c28(2, &D_801CC000, 0x40000, 0x4000);
        this->field44_0x58 = 0;
        this->assets_file = ptr_FUN_80000d80(2, 0x30000);
        DMAMgr_load_NisitenmaIchigo_File(ptr_DMAMgr, ASSETS_DATA_SCREEN, (u32)this->assets_file, &this->field44_0x58);
        FUN_8000f280(ASSETS_DATA_SCREEN);
        ptr_FUN_8000219c(this, 0, 0x28, 0);
        ptr_goToNextFunc((s8*)this->header.current_function, &this->header.functionLoadMgr_ID);
    }
}

// https://decomp.me/scratch/vFQrj (Matched by anon)
// 0x8012a688
void stageSelect_initGraphics(stageSelect* this) {
    model_info* bg_model;
    textbox** textbox_array = this->textboxes;

    textbox* (*ptr_textbox_create)(void* parent_module, void* param_2, u32 flags) = &textbox_create;
    void (*ptr_textbox_setPos)(textbox* this, u16 text_X_pos, u16 text_Y_pos, s32 unused) = &textbox_setPos;
    void (*ptr_textbox_setDimensions)(textbox* this, s8 height, s16 width, u8 param_4, u8 character_spacing) = &textbox_setDimensions;
    void (*ptr_textbox_setMessagePtr)(textbox* this, u16* text, s32 param_3, s16 param_4) = &textbox_setMessagePtr;
    void (*ptr_textbox_8012cd54) (textbox* this, u32 param_2, u8 param_3, u8 param_4) = &textbox_8012cd54;
    void (*ptr_func_80040570)() = &func_80040570;
    void (*ptr_goToNextFunc)(s8* functionLoadMgr, s16* functionLoadMgr_ID) = &goToNextFunc;
            
    if (this->field44_0x58 != 0) {
        func_80000FB4(this->assets_file, (u32)this->field44_0x58 - (u32)this->assets_file);
        bg_model = func_80004E68(0x10, D_8009B444);
        this->red_background_model = bg_model;
        bg_model->assets_file_ID = ASSETS_DATA_SCREEN;
        bg_model->display_list_address = (u32)0x06016D10;
        bg_model->field1_0x2 |= 0x0800;
        bg_model->ambient_color = 0xFFFFFFFF;
        bg_model->position.x = 0.0f;
        bg_model->position.y = 0.0f;
        bg_model->position.z = 0.0f;
        bg_model->size.x = 1.0f;
        bg_model->size.y = 1.0f;
        bg_model->size.z = 1.0f;
        
        for (this->text_ID = 0; this->text_ID < 9; this->text_ID++) {
            textbox_array[this->text_ID] = ptr_textbox_create(this, D_8009B444, 0x08600000);
            if (textbox_array[this->text_ID] == 0) {
                continue;
            }
            else {
                textbox_array[this->text_ID]->color_palette = 0;
                if (this->text_ID != 0) {
                    ptr_textbox_setPos(textbox_array[this->text_ID], 30, (this->text_ID * 23) + 23, 1);
                }
                else {
                    textbox_array[this->text_ID]->color_palette = 2;
                    ptr_textbox_setPos(textbox_array[this->text_ID], 100, 10, 1);
                    ptr_textbox_8012cd54(textbox_array[this->text_ID], 1, 2, 1);
                }
                ptr_textbox_setDimensions(textbox_array[this->text_ID], 1, 300, 0, 0);
                ptr_textbox_setMessagePtr(textbox_array[this->text_ID], text_getMessageFromPool(stageSelect_text, this->text_ID), 0, 0);
            }
        }
        ptr_func_80040570();
        ptr_goToNextFunc((s8*)this->header.current_function, &this->header.functionLoadMgr_ID);
    }
}

// 0x8012a904
void stageSelect_initMenuButton(stageSelect* this) {
    menuButton* button;
    textbox** textbox_array = this->textboxes;

    u32 (*ptr_fade_isFading)() = fade_isFading;
    menuButton* (*ptr_menuButton_create)(void* param_1, void* param_2, u32 flags, f32 param_4, f32 param_5, f32 param_6, f32 param_7, f32 param_8, f32 param_9) = &menuButton_create;
    void (*ptr_D_801365EC)(void*, s32, s32, s32, f32, f32, s32) = &D_801365EC;
    void (*ptr_goToNextFunc)(s8* functionLoadMgr, s16* functionLoadMgr_ID) = &goToNextFunc;
    
    if (ptr_fade_isFading() == 0) {
        for (this->text_ID = 0; this->text_ID < 9; this->text_ID++) {
            if ((textbox_array[this->text_ID]->flags & TEXTBOX_IS_ACTIVE) == 0) {
                return;
            }
        }
        this->menuButton = ptr_menuButton_create(this, D_8009B450, 0x008000B5, -120.0f, 61.0f, 10.0f, 2.0f, 240.0f, 90.0f);
        button = this->menuButton;
        if (button != 0) {
            ptr_D_801365EC(button, 0, 7, 5, D_8018AEC8, 1.0f, 0);
            button->flags &= ~0x100;
            button->flags |= 0x200;
        }
        ptr_goToNextFunc((s8*)this->header.current_function, &this->header.functionLoadMgr_ID);
    }
}

// https://decomp.me/scratch/W2jbO
// 0x8012aa60
void stageSelect_moveButton(stageSelect* this) {
    menuButton* button = this->menuButton;
    s32 current_option;
    s8 previous_option;
    
    s32 (*ptr_menuButton_selectNextOption)(s32* option, s16* param_2, s16 option_max) = menuButton_selectNextOption;
    void (*ptr_goToNextFunc)(s8* functionLoadMgr, s16* functionLoadMgr_ID) = goToNextFunc;
    
    if (this->button_is_moving != 0) {
        this->button_move_offset = this->button_transition_rate / 4;
        if ((f64)this->button_move_offset >= 1) {
            this->button_is_moving = 0;
            this->button_move_offset = 1;
        }
        button->position.y = (this->button_move_offset * this->field56_0x70) + this->text_ID;
        this->button_transition_rate += 1.0;
        return;
    }
    current_option = this->current_option;
    previous_option = this->previous_option;
    if ((u32)current_option == previous_option) {
        if ((controllers[0].buttons_pressed & A_BUTTON) || (controllers[0].buttons_pressed & RECENTER_BUTTON)) {
            button->flags = button->flags & ~0x200;
            button->flags |= 0x100;
            ptr_goToNextFunc((s8*)this->header.current_function, &this->header.functionLoadMgr_ID);
        }
        else {
            ptr_menuButton_selectNextOption(&this->current_option, &this->header.field_0x04, 8);
        }
        return;
    }
    this->button_is_moving = 1;
    this->previous_option = current_option;
    this->text_ID = (61 - ((f64)previous_option * 23));
    this->field46_0x5d = (61 - ((f64)current_option * 23));
    this->button_transition_rate = 0;
    this->field56_0x70 = (s16)(this->field46_0x5d - this->text_ID);
}

// https://decomp.me/scratch/qrzft
// 0x8012ac04
void stageSelect_warpToStage(stageSelect* this) {
    s16 i;
    menuButton* button = this->menuButton;
    void (*ptr_goToNextFunc)(s8* functionLoadMgr, s16* functionLoadMgr_ID) = goToNextFunc;
    
    if ((button->flags & PRESSED_DOWN) >> 0xE != 0) {
        stageSelect_closeTextboxes(this);
        D_80383AB8.SaveState_game.map_ID = NONE;
        D_80383AB8.SaveState_game.map_entrance_ID = -1;
        D_80383AB8.SaveState_game.life = 100;
        D_80383AB8.SaveState_game.field13_0x5c = 100;
        D_80383AB8.SaveState_game.subweapon = 0;
        D_80383AB8.SaveState_game.money = 0;
        D_80383AB8.SaveState_game.player_flags = 0;
        // Remove inventory items
        for (i = 1; i < 42; i++) {
            D_80363AB8[1].SaveState_game.inventory_items_amount[i - 1] = 0;
        }
        D_80383AB8.SaveState_game.weeks_passed = 0;
        D_80383AB8.SaveState_game.day = 0;
        D_80383AB8.SaveState_game.hour = 0;
        D_80383AB8.SaveState_game.minute = 0;
        D_80383AB8.SaveState_game.seconds = 0;
        D_80383AB8.SaveState_game.milliseconds = 0;
        // Clear event flags (doesn't appear to match with a 'for' loop)
        i = 0;
        do {
            D_80363AB8[1].SaveState_game.event_flags[i] = 0,
            i++;
        } while (i < 16);
        D_80383AB8.field25453_0x644c = 0;
        D_80383AB8.cutscene_flags &= ~0x1;
        D_80383AB8.field25313_0x63c0 = 0;
        switch (this->current_option) {
            case FOREST:
                D_80383AB8.entrance_cutscene = 60;
                D_80383AB8.map_fade_out_time = 30;
                D_80383AB8.map_fade_in_time = 30;
                D_80383AB8.map_ID = MORI;
                D_80383AB8.map_entrance_ID = 0;
                D_80383AB8.map_fade_in_color.R = 0;
                D_80383AB8.map_fade_in_color.G = 0;
                D_80383AB8.map_fade_in_color.B = 0;
                break;
            case INSIDE_OF_RAMPART:
                D_80383AB8.entrance_cutscene = 4;
                D_80383AB8.map_ID = TOUOKUJI;
                D_80383AB8.map_fade_out_time = 30;
                D_80383AB8.map_fade_in_time = 30;
                D_80383AB8.map_entrance_ID = 0;
                D_80383AB8.map_fade_in_color.R = 0;
                D_80383AB8.map_fade_in_color.G = 0;
                D_80383AB8.map_fade_in_color.B = 0;
                break;
            case COURTYARD:
                D_80383AB8.cutscene_flags |= 0x10;
                D_80383AB8.entrance_cutscene = 9;
                D_80383AB8.map_ID = NAKANIWA;
                D_80383AB8.map_fade_out_time = 30;
                D_80383AB8.map_fade_in_time = 30;
                D_80383AB8.map_entrance_ID = 0;
                D_80383AB8.map_fade_in_color.R = 0;
                D_80383AB8.map_fade_in_color.G = 0;
                D_80383AB8.map_fade_in_color.B = 0;
                break;
            case EXECUTION_TOWER:
                D_80383AB8.map_ID = SHOKEI_TOU;
                D_80383AB8.map_fade_out_time = 30;
                D_80383AB8.map_fade_in_time = 30;
                D_80383AB8.map_entrance_ID = 0;
                D_80383AB8.map_fade_in_color.R = 0;
                D_80383AB8.map_fade_in_color.G = 0;
                D_80383AB8.map_fade_in_color.B = 0;
                break;
            case CLOCK_TOWER:
                D_80383AB8.map_ID = TOKEITOU_NAI;
                D_80383AB8.map_fade_out_time = 30;
                D_80383AB8.map_fade_in_time = 30;
                D_80383AB8.map_entrance_ID = 0;
                D_80383AB8.map_fade_in_color.R = 0;
                D_80383AB8.map_fade_in_color.G = 0;
                D_80383AB8.map_fade_in_color.B = 0;
                break;
            case VS_DEATH:
                D_80383AB8.map_ID = TURO_TOKEITOU,      // Comma needed for matching
                D_80383AB8.map_entrance_ID = 1;
                D_80383AB8.map_fade_out_time = 30;
                D_80383AB8.map_fade_in_time = 30;
                D_80383AB8.map_fade_in_color.R = 0;
                D_80383AB8.map_fade_in_color.G = 0;
                D_80383AB8.map_fade_in_color.B = 0;
                break;
            case VS_ACTRIESE:
                D_80383AB8.map_ID = TURO_TOKEITOU;
                D_80383AB8.map_fade_out_time = 30;
                D_80383AB8.map_fade_in_time = 30;
                D_80383AB8.map_entrance_ID = 0;
                D_80383AB8.map_fade_in_color.R = 0;
                D_80383AB8.map_fade_in_color.G = 0;
                D_80383AB8.map_fade_in_color.B = 0;
                break;
            case VS_BEHIMOS:
                D_80383AB8.map_ID = HONMARU_B1F;
                D_80383AB8.map_fade_out_time = 30;
                D_80383AB8.map_fade_in_time = 30;
                D_80383AB8.map_entrance_ID = 0;
                D_80383AB8.map_fade_in_color.R = 0;
                D_80383AB8.map_fade_in_color.G = 0;
                D_80383AB8.map_fade_in_color.B = 0;
                break;
        }
        GameStateMgr_changeGameState(GAMEPLAY);
        ptr_goToNextFunc((s8*)this->header.current_function, &this->header.functionLoadMgr_ID);
    }
}

// 0x8012aea0
void stageSelect_closeTextboxes(stageSelect* this) {
    textbox** textbox_array = this->textboxes;
    void (*ptr_func_80000C78)(s32 param_1) = func_80000C78;

    this->menuButton->flags |= 0x300;
    for (this->text_ID = 0; this->text_ID < 9; this->text_ID++) {
        textbox_array[this->text_ID]->flags |= CLOSE_TEXTBOX;
    }
    ptr_func_80000C78(2);
}
