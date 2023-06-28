/*
 * File: stageSelect.c
 * Description: Unused Stage Select
 * ID = 0x141
 * osMapTLB'd? = No
 * Entrypoint = 0x8012A520
 * Associated Files = -
 */

#include "../include/cv64.h"
#include "../include/stageSelect.h"

// https://decomp.me/scratch/fMxJW
// 0x8012a520
void stageSelect_entrypoint(stageSelect* self) {
    s16 func_ID;
    
    func_ID = self->header.functionInfo_ID + 1;
    self->header.functionInfo_ID = func_ID,        // Comma needed for matching
    self->header.current_function[func_ID].timer++;
    stageSelect_functions[self->header.current_function[func_ID].function](self);
    self->header.functionInfo_ID--;
}

// 0x8012a590
void stageSelect_init(stageSelect* self) {
    u32 (*ptr_fade_isFading)() = fade_isFading;
    void (*ptr_fade_setSettings)(u16, u16, u8, u8, u8) = fade_setSettings;
    void (*ptr_allocatedBlockInfo_init)(s32, s16*, s32, s16) = allocatedBlockInfo_init;
    void* (*ptr_malloc)(s32, s32) = malloc;
    void (*ptr_module_allocEntryInList)(void*, s32, s32, u32) = module_allocEntryInList;
    void (*ptr_goToNextFunc)(u16[], s16*) = goToNextFunc;

    if ((ptr_fade_isFading() == FALSE) && (ptr_DMAMgr->DMAChunkMgr != NULL)) {
        ptr_fade_setSettings(FADE_IN, 30, 0, 0, 0);
        D_80383AB8.cutscene_flags = 0;
        ptr_allocatedBlockInfo_init(2, &D_801CC000, 0x40000, 0x4000);
        self->assets_file_end_ptr = NULL;
        self->assets_file_start_ptr = ptr_malloc(2, 0x30000);
        DMAMgr_loadNisitenmaIchigoFile(ptr_DMAMgr, ASSETS_DATA_SCREEN, (u32) self->assets_file_start_ptr, &self->assets_file_end_ptr);
        NisitenmaIchigo_checkAndStoreLoadedFile(ASSETS_DATA_SCREEN);
        ptr_module_allocEntryInList(self, 0, sizeof(textbox* [10]), 0);
        ptr_goToNextFunc(self->header.current_function, &self->header.functionInfo_ID);
    }
}

// https://decomp.me/scratch/vFQrj (Matched by anon)
// 0x8012a688
void stageSelect_initGraphics(stageSelect* self) {
    model_info* bg_model;
    textbox** textbox_array = self->textboxes;

    textbox* (*ptr_textbox_create)(void*, void*, u32) = textbox_create;
    void (*ptr_textbox_setPos)(textbox*, u16, u16, s32) = textbox_setPos;
    void (*ptr_textbox_setDimensions)(textbox*, s8, s16, u8, u8) = textbox_setDimensions;
    void (*ptr_textbox_setMessagePtr)(textbox*, u16*, s32, s16) = textbox_setMessagePtr;
    void (*ptr_textbox_8012cd54) (textbox*, u32, u8, u8) = textbox_8012cd54;
    void (*ptr_func_80040570)() = func_80040570;
    void (*ptr_goToNextFunc)(u16[], s16*) = goToNextFunc;
            
    if (self->assets_file_end_ptr != NULL) {
        allocatedBlockHeader_updateBlockMaxSize(self->assets_file_start_ptr, (u32) self->assets_file_end_ptr - (u32) self->assets_file_start_ptr);
        bg_model = modelInfo_createRootNode(HUD_ELEMENT, D_8009B444);
        self->red_background_model = bg_model;
        bg_model->assets_file_ID = ASSETS_DATA_SCREEN;
        bg_model->display_list_address = (u32) 0x06016D10;
        bg_model->flags |= 0x0800;
        bg_model->ambient_color = 0xFFFFFFFF;
        bg_model->position.x = 0.0f;
        bg_model->position.y = 0.0f;
        bg_model->position.z = 0.0f;
        bg_model->size.x = 1.0f;
        bg_model->size.y = 1.0f;
        bg_model->size.z = 1.0f;
        
        for (self->text_ID = 0; self->text_ID < 9; self->text_ID++) {
            textbox_array[self->text_ID] = ptr_textbox_create(self, D_8009B444, 0x08600000);
            if (textbox_array[self->text_ID] == 0) {
                continue;
            }
            else {
                textbox_array[self->text_ID]->color_palette = 0;
                if (self->text_ID != 0) {
                    ptr_textbox_setPos(textbox_array[self->text_ID], 30, (self->text_ID * 23) + 23, 1);
                }
                else {
                    textbox_array[self->text_ID]->color_palette = 2;
                    ptr_textbox_setPos(textbox_array[self->text_ID], 100, 10, 1);
                    ptr_textbox_8012cd54(textbox_array[self->text_ID], 1, 2, 1);
                }
                ptr_textbox_setDimensions(textbox_array[self->text_ID], 1, 300, 0, 0);
                ptr_textbox_setMessagePtr(textbox_array[self->text_ID], text_getMessageFromPool(stageSelect_text, self->text_ID), 0, 0);
            }
        }
        ptr_func_80040570();
        ptr_goToNextFunc(self->header.current_function, &self->header.functionInfo_ID);
    }
}

// 0x8012a904
void stageSelect_initMenuButton(stageSelect* self) {
    menuButton* button;
    textbox** textbox_array = self->textboxes;

    u32 (*ptr_fade_isFading)() = fade_isFading;
    menuButton* (*ptr_menuButton_create)(void*, void*, u32, f32, f32, f32, f32, f32, f32) = menuButton_create;
    void (*ptr_D_801365EC)(void*, s32, s32, s32, f32, f32, s32) = D_801365EC;
    void (*ptr_goToNextFunc)(u16[], s16*) = goToNextFunc;
    
    if (ptr_fade_isFading() == FALSE) {
        for (self->text_ID = 0; self->text_ID < 9; self->text_ID++) {
            if ((textbox_array[self->text_ID]->flags & TEXTBOX_IS_ACTIVE) == 0) {
                return;
            }
        }
        self->menuButton = ptr_menuButton_create(self, HUD_camera, 0x008000B5, -120.0f, 61.0f, 10.0f, 2.0f, 240.0f, 90.0f);
        button = self->menuButton;
        if (button != NULL) {
            ptr_D_801365EC(button, 0, 7, 5, lens_background_size, 1.0f, 0);
            button->flags &= ~0x100;
            button->flags |= 0x200;
        }
        ptr_goToNextFunc(self->header.current_function, &self->header.functionInfo_ID);
    }
}

// https://decomp.me/scratch/W2jbO
// 0x8012aa60
void stageSelect_moveButton(stageSelect* self) {
    menuButton* button = self->menuButton;
    s32 current_option;
    s8 previous_option;
    
    s32 (*ptr_menuButton_selectNextOption)(s32*, s16*, s16) = menuButton_selectNextOption;
    void (*ptr_goToNextFunc)(u16[], s16*) = goToNextFunc;
    
    if (self->button_is_moving != FALSE) {
        self->button_move_offset = self->button_transition_rate / 4;
        if ((f64) self->button_move_offset >= 1) {
            self->button_is_moving = 0;
            self->button_move_offset = 1;
        }
        button->position.y = (self->button_move_offset * self->field56_0x70) + self->text_ID;
        self->button_transition_rate += 1.0;
        return;
    }
    current_option = self->current_option;
    previous_option = self->previous_option;
    if ((u32) current_option == previous_option) {
        if ((controllers[0].buttons_pressed & A_BUTTON) || (controllers[0].buttons_pressed & RECENTER_BUTTON)) {
            button->flags = button->flags & ~0x200;
            button->flags |= 0x100;
            ptr_goToNextFunc(self->header.current_function, &self->header.functionInfo_ID);
        }
        else {
            ptr_menuButton_selectNextOption(&self->current_option, &self->header.field_0x04, 8);
        }
        return;
    }
    self->button_is_moving = 1;
    self->previous_option = current_option;
    self->text_ID = (61 - ((f64) previous_option * 23));
    self->field46_0x5d = (61 - ((f64) current_option * 23));
    self->button_transition_rate = 0;
    self->field56_0x70 = (s16) (self->field46_0x5d - self->text_ID);
}

// https://decomp.me/scratch/qrzft
// 0x8012ac04
void stageSelect_warpToStage(stageSelect* self) {
    s16 i;
    menuButton* button = self->menuButton;
    void (*ptr_goToNextFunc)(u16[], s16*) = goToNextFunc;
    
    if ((button->flags & PRESSED_DOWN) >> 0xE != FALSE) {
        stageSelect_closeTextboxes(self);
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
        switch (self->current_option) {
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
        ptr_goToNextFunc(self->header.current_function, &self->header.functionInfo_ID);
    }
}

// 0x8012aea0
void stageSelect_closeTextboxes(stageSelect* self) {
    textbox** textbox_array = self->textboxes;
    void (*ptr_allocatedBlockInfo_resetFlags)(s32) = allocatedBlockInfo_resetFlags;

    self->menuButton->flags |= 0x300;
    for (self->text_ID = 0; self->text_ID < 9; self->text_ID++) {
        textbox_array[self->text_ID]->flags |= CLOSE_TEXTBOX;
    }
    ptr_allocatedBlockInfo_resetFlags(2);
}
