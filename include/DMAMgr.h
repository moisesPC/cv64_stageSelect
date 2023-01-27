#ifndef DMAMGR_H
#define DMAMGR_H

#include "n64types.h"
#include "modules.h"

enum Nisitenma_Ichigo_files {
    ASSETS_DATA_SCREEN = 0x60
};

typedef struct {
    u8 chunk_buffer[0x800];
    u8* ROM_address_chunk;
    u8* ROM_address_chunk_current_u8_to_load; /* Added by +1 */
    s32 file_chunk_read_limit; /* Ex. 0xA800, Substracted by -800 when "file_u8s_left_to_read" is equal to this variable */
    s32 file_u8s_left_to_read; /* Ex. 0xAFFF, Substracted by -1 */
    s32 chunk_u8s_left_to_read; /* Substracted by -1 */
    u8 field6_0x814;
    u8 field7_0x815;
    u8 field8_0x816;
    u8 field9_0x817;
    u8* ptr_u8_to_load_from_chunk_buffer;
    u8 field11_0x81c;
    u8 field12_0x81d;
    u8 field13_0x81e;
    u8 field14_0x81f;
    u8 field15_0x820;
    u8 field16_0x821;
    u8 field17_0x822;
    u8 field18_0x823;
    u8 field19_0x824;
    u8 field20_0x825;
    u8 field21_0x826;
    u8 field22_0x827;
    u8* file_ROM_start_address;
    u8* file_RAM_start_address;
    s32 file_size;
    u32 field26_0x834;
    u32 file_alignment;
    u32 field28_0x83c;
    s32 file_ID;
    s16 field30_0x844;
    s16 field31_0x846;
    u8 ROM_start_address_array;
    u8 field33_0x849;
    u8 field34_0x84a;
    u8 field35_0x84b;
    u8 RAM_address_array;
    u8 field37_0x84d;
    u8 field38_0x84e;
    u8 field39_0x84f;
    u8 size_array;
    u8 field41_0x851;
    u8 field42_0x852;
    u8 field43_0x853;
    u8 compressed_file_ID_array;
    u8 field45_0x855;
    u8 field46_0x856;
    u8 field47_0x857;
    void* field48_0x858;
} DMAChunkMgr;

typedef struct {
    ModuleHeader header;
    u8 field1_0x20;
    u8 field2_0x21;
    s16 field3_0x22;
    void* field4_0x24;
    void* field5_0x28;
    void* field6_0x2c;
    void* field7_0x30;
    DMAChunkMgr* DMAChunkMgr;
    void* field9_0x38;
    void* field10_0x3c;
    void* field11_0x40;
    void* field12_0x44;
    void* field13_0x48;
    void* field14_0x4c;
    void* field15_0x50;
    void* field16_0x54;
    void* field17_0x58;
    void* field18_0x5c;
    void* field19_0x60;
    void* field20_0x64;
    void* field21_0x68;
    void* field22_0x6c;
    void* field23_0x70;
} DMAMgr;

extern DMAMgr* ptr_DMAMgr;
extern void* DMAMgr_load_NisitenmaIchigo_File(DMAMgr* this, s32 file_ID, u32 dest, void* param_4);

#endif
