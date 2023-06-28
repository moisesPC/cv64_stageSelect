#ifndef MODULES_H
#define MODULES_H

#include "n64types.h"

typedef struct {
    u8 timer;                // Could also be number of accesses to function
    u8 function;             // Function ID
} functionInfo;              // Size = 0x2

struct ModuleHeader {
    s16 ID;
    s16 flags;
    s16 field_0x04;
    s16 field_0x06;
    functionInfo current_function[3];
    s16 functionInfo_ID;
    void (*destroy)(void*);
    struct ModuleHeader* parent;
    struct ModuleHeader* next;
    struct ModuleHeader* child;
};                    // Size = 0x20
typedef struct ModuleHeader ModuleHeader;

enum ModuleHeader_flags {
    PAUSE = 0x4000,
    PARENT_MODULE = 0x8000
};

extern void goToNextFunc(u16 current_functionInfo[], s16* functionInfo_ID);
extern ModuleHeader* module_allocate(s32 ID);
extern s32 func_8000EE18(ModuleHeader* param_1, ModuleHeader* param_2);
extern void* modules_file_info[555];
extern ModuleHeader* D_800A78A0;
extern u16 Modules_number_of_instances_per_module[555];
extern void func_80002740(ModuleHeader* param_1);

#endif
