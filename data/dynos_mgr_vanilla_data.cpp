#include "dynos.cpp.h"
extern "C" {
#include "behavior_table.h"
#include "levels/scripts.h"

#include "levels/bbh/header.h"
#include "levels/bitdw/header.h"
#include "levels/bitfs/header.h"
#include "levels/bits/header.h"
#include "levels/bob/header.h"
#include "levels/bowser_1/header.h"
#include "levels/bowser_2/header.h"
#include "levels/bowser_2/header.h"
#include "levels/bowser_3/header.h"
#include "levels/bowser_3/header.h"
#include "levels/castle_courtyard/header.h"
#include "levels/castle_grounds/header.h"
#include "levels/castle_inside/header.h"
#include "levels/ccm/header.h"
#include "levels/ddd/header.h"
#include "levels/hmc/header.h"
#include "levels/jrb/header.h"
#include "levels/lll/header.h"
#include "levels/pss/header.h"
#include "levels/rr/header.h"
#include "levels/sa/header.h"
#include "levels/sl/header.h"
#include "levels/ssl/header.h"
#include "levels/thi/header.h"
#include "levels/totwc/header.h"
#include "levels/ttc/header.h"
#include "levels/ttm/header.h"
#include "levels/vcutm/header.h"
#include "levels/wdw/header.h"
#include "levels/wf/header.h"
#include "levels/wmotr/header.h"

#include "textures.h"
}


#define MGR_FIND_DATA(_DataTable, _Cast)                               \
    size_t _count = sizeof(_DataTable) / (2 * sizeof(_DataTable[0]));  \
    for (u32 _i = 0; _i < _count; _i++) {                              \
        if (!strcmp((const char*)_DataTable[_i * 2 + 0], aDataName)) { \
            return _Cast _DataTable[_i * 2 + 1];                       \
        }                                                              \
    }                                                                  \
    return NULL;

#define MGR_FIND_NAME(_DataTable)                                      \
    size_t _count = sizeof(_DataTable) / (2 * sizeof(_DataTable[0]));  \
    for (u32 _i = 0; _i < _count; _i++) {                              \
        if ((const void*)_DataTable[_i * 2 + 1] == aData) {            \
            return (const char*)_DataTable[_i * 2 + 0];                \
        }                                                              \
    }                                                                  \
    return NULL;

  ///////////////////////
 // Function Pointers //
///////////////////////

#define define_vanilla_script_ptr(ptr) (const void*)#ptr, (const void*)ptr

static const void* sDynosVanillaScriptPtrs[] = {
    define_vanilla_script_ptr(level_main_scripts_entry),
    define_vanilla_script_ptr(script_func_global_1),
    define_vanilla_script_ptr(script_func_global_2),
    define_vanilla_script_ptr(script_func_global_3),
    define_vanilla_script_ptr(script_func_global_4),
    define_vanilla_script_ptr(script_func_global_5),
    define_vanilla_script_ptr(script_func_global_6),
    define_vanilla_script_ptr(script_func_global_7),
    define_vanilla_script_ptr(script_func_global_8),
    define_vanilla_script_ptr(script_func_global_9),
    define_vanilla_script_ptr(script_func_global_10),
    define_vanilla_script_ptr(script_func_global_11),
    define_vanilla_script_ptr(script_func_global_12),
    define_vanilla_script_ptr(script_func_global_13),
    define_vanilla_script_ptr(script_func_global_14),
    define_vanilla_script_ptr(script_func_global_15),
    define_vanilla_script_ptr(script_func_global_16),
    define_vanilla_script_ptr(script_func_global_17),
    define_vanilla_script_ptr(script_func_global_18),
};

const void* DynOS_Mgr_VanillaScriptPtr_GetFromName(const char* aDataName) {
    MGR_FIND_DATA(sDynosVanillaScriptPtrs, (const void*));
}

const char* DynOS_Mgr_VanillaScriptPtr_GetFromData(const void* aData) {
    MGR_FIND_NAME(sDynosVanillaScriptPtrs);
}

  ////////////////
 // Level Geos //
////////////////

#define define_vanilla_lvl_geo(tex) (const void*) #tex, (const void*) tex
static const void* sDynosVanillaLvlGeos[] = {
    define_vanilla_lvl_geo(bitfs_geo_0004B0),
    define_vanilla_lvl_geo(bitfs_geo_0004C8),
    define_vanilla_lvl_geo(bitfs_geo_0004E0),
    define_vanilla_lvl_geo(bitfs_geo_0004F8),
    define_vanilla_lvl_geo(bitfs_geo_000510),
    define_vanilla_lvl_geo(bitfs_geo_000528),
    define_vanilla_lvl_geo(bitfs_geo_000540),
    define_vanilla_lvl_geo(bitfs_geo_000558),
    define_vanilla_lvl_geo(bitfs_geo_000570),
    define_vanilla_lvl_geo(bitfs_geo_000588),
    define_vanilla_lvl_geo(bitfs_geo_0005A0),
    define_vanilla_lvl_geo(bitfs_geo_0005B8),
    define_vanilla_lvl_geo(bitfs_geo_0005D0),
    define_vanilla_lvl_geo(bitfs_geo_0005E8),
    define_vanilla_lvl_geo(bitfs_geo_000600),
    define_vanilla_lvl_geo(bitfs_geo_000618),
    define_vanilla_lvl_geo(bitfs_geo_000630),
    define_vanilla_lvl_geo(bitfs_geo_000648),
    define_vanilla_lvl_geo(bitfs_geo_000660),
    define_vanilla_lvl_geo(bitfs_geo_000678),
    define_vanilla_lvl_geo(bitfs_geo_000690),
    define_vanilla_lvl_geo(bitfs_geo_0006A8),
    define_vanilla_lvl_geo(bitfs_geo_0006C0),
    define_vanilla_lvl_geo(bitfs_geo_0006D8),
    define_vanilla_lvl_geo(bitfs_geo_0006F0),
    define_vanilla_lvl_geo(bitfs_geo_000708),
    define_vanilla_lvl_geo(bitfs_geo_000728),
    define_vanilla_lvl_geo(bitfs_geo_000740),
    define_vanilla_lvl_geo(bitfs_geo_000758),
    define_vanilla_lvl_geo(bitfs_geo_000770),
    define_vanilla_lvl_geo(bitfs_geo_000788),
    define_vanilla_lvl_geo(bitfs_geo_0007A0),
    define_vanilla_lvl_geo(bits_geo_000430),
    define_vanilla_lvl_geo(bits_geo_000448),
    define_vanilla_lvl_geo(bits_geo_000460),
    define_vanilla_lvl_geo(bits_geo_000478),
    define_vanilla_lvl_geo(bits_geo_000490),
    define_vanilla_lvl_geo(bits_geo_0004A8),
    define_vanilla_lvl_geo(bits_geo_0004C0),
    define_vanilla_lvl_geo(bits_geo_0004D8),
    define_vanilla_lvl_geo(bits_geo_0004F0),
    define_vanilla_lvl_geo(bits_geo_000508),
    define_vanilla_lvl_geo(bits_geo_000520),
    define_vanilla_lvl_geo(bits_geo_000538),
    define_vanilla_lvl_geo(bits_geo_000550),
    define_vanilla_lvl_geo(bits_geo_000568),
    define_vanilla_lvl_geo(bits_geo_000580),
    define_vanilla_lvl_geo(bits_geo_000598),
    define_vanilla_lvl_geo(bits_geo_0005B0),
    define_vanilla_lvl_geo(bits_geo_0005C8),
    define_vanilla_lvl_geo(bits_geo_0005E0),
    define_vanilla_lvl_geo(bits_geo_0005F8),
    define_vanilla_lvl_geo(bits_geo_000610),
    define_vanilla_lvl_geo(bits_geo_000628),
    define_vanilla_lvl_geo(bits_geo_000640),
    define_vanilla_lvl_geo(bits_geo_000658),
    define_vanilla_lvl_geo(bits_geo_000670),
    define_vanilla_lvl_geo(bits_geo_000688),
    define_vanilla_lvl_geo(bits_geo_0006A0),
    define_vanilla_lvl_geo(bits_geo_0006B8),
    define_vanilla_lvl_geo(bits_geo_0006D0),
    define_vanilla_lvl_geo(bits_geo_0006E8),
    define_vanilla_lvl_geo(bits_geo_000700),
    define_vanilla_lvl_geo(bits_geo_000718),
    define_vanilla_lvl_geo(bob_geo_000440),
    define_vanilla_lvl_geo(bob_geo_000458),
    define_vanilla_lvl_geo(bob_geo_000470),
    define_vanilla_lvl_geo(bob_geo_000488),
    define_vanilla_lvl_geo(bowser_1_geo_0000D0),
    define_vanilla_lvl_geo(bowser_2_geo_000170),
    define_vanilla_lvl_geo(bowser_2_geo_000170),
    define_vanilla_lvl_geo(bowser_2_geo_000188),
    define_vanilla_lvl_geo(bowser_2_geo_000188),
    define_vanilla_lvl_geo(bowser_3_geo_000290),
    define_vanilla_lvl_geo(bowser_3_geo_000290),
    define_vanilla_lvl_geo(bowser_3_geo_0002A8),
    define_vanilla_lvl_geo(bowser_3_geo_0002A8),
    define_vanilla_lvl_geo(bowser_3_geo_0002C0),
    define_vanilla_lvl_geo(bowser_3_geo_0002C0),
    define_vanilla_lvl_geo(bowser_3_geo_0002D8),
    define_vanilla_lvl_geo(bowser_3_geo_0002D8),
    define_vanilla_lvl_geo(bowser_3_geo_0002F0),
    define_vanilla_lvl_geo(bowser_3_geo_0002F0),
    define_vanilla_lvl_geo(bowser_3_geo_000308),
    define_vanilla_lvl_geo(bowser_3_geo_000308),
    define_vanilla_lvl_geo(bowser_3_geo_000320),
    define_vanilla_lvl_geo(bowser_3_geo_000320),
    define_vanilla_lvl_geo(bowser_3_geo_000338),
    define_vanilla_lvl_geo(bowser_3_geo_000338),
    define_vanilla_lvl_geo(bowser_3_geo_000350),
    define_vanilla_lvl_geo(bowser_3_geo_000350),
    define_vanilla_lvl_geo(bowser_3_geo_000368),
    define_vanilla_lvl_geo(bowser_3_geo_000368),
    define_vanilla_lvl_geo(bowser_3_geo_000380),
    define_vanilla_lvl_geo(bowser_3_geo_000380),
    define_vanilla_lvl_geo(bowser_3_geo_000398),
    define_vanilla_lvl_geo(bowser_3_geo_000398),
    define_vanilla_lvl_geo(castle_courtyard_geo_000200),
    define_vanilla_lvl_geo(castle_courtyard_geo_000218),
    define_vanilla_lvl_geo(castle_geo_000F00),
    define_vanilla_lvl_geo(castle_geo_000F18),
    define_vanilla_lvl_geo(castle_geo_000F30),
    define_vanilla_lvl_geo(castle_geo_000F70),
    define_vanilla_lvl_geo(castle_geo_000F88),
    define_vanilla_lvl_geo(castle_geo_000FA8),
    define_vanilla_lvl_geo(castle_geo_000FD0),
    define_vanilla_lvl_geo(castle_geo_001000),
    define_vanilla_lvl_geo(castle_geo_001038),
    define_vanilla_lvl_geo(castle_geo_001088),
    define_vanilla_lvl_geo(castle_geo_0010C8),
    define_vanilla_lvl_geo(castle_geo_001110),
    define_vanilla_lvl_geo(castle_geo_001158),
    define_vanilla_lvl_geo(castle_geo_0011A8),
    define_vanilla_lvl_geo(castle_geo_001200),
    define_vanilla_lvl_geo(castle_geo_001260),
    define_vanilla_lvl_geo(castle_geo_0012C8),
    define_vanilla_lvl_geo(castle_geo_001348),
    define_vanilla_lvl_geo(castle_geo_0013B8),
    define_vanilla_lvl_geo(castle_geo_001400),
    define_vanilla_lvl_geo(castle_geo_001518),
    define_vanilla_lvl_geo(castle_geo_001530),
    define_vanilla_lvl_geo(castle_geo_001548),
    define_vanilla_lvl_geo(castle_geo_001560),
    define_vanilla_lvl_geo(castle_geo_001578),
    define_vanilla_lvl_geo(castle_geo_0015B8),
    define_vanilla_lvl_geo(castle_geo_0015F8),
    define_vanilla_lvl_geo(castle_geo_001628),
    define_vanilla_lvl_geo(castle_geo_001668),
    define_vanilla_lvl_geo(castle_geo_001690),
    define_vanilla_lvl_geo(castle_geo_0016D8),
    define_vanilla_lvl_geo(castle_geo_001740),
    define_vanilla_lvl_geo(castle_geo_001798),
    define_vanilla_lvl_geo(castle_geo_001800),
    define_vanilla_lvl_geo(castle_geo_001858),
    define_vanilla_lvl_geo(castle_geo_001940),
    define_vanilla_lvl_geo(castle_geo_001958),
    define_vanilla_lvl_geo(castle_geo_001980),
    define_vanilla_lvl_geo(castle_geo_0019C8),
    define_vanilla_lvl_geo(castle_geo_0019F8),
    define_vanilla_lvl_geo(castle_geo_001A30),
    define_vanilla_lvl_geo(castle_geo_001A58),
    define_vanilla_lvl_geo(castle_geo_001AB8),
    define_vanilla_lvl_geo(castle_geo_001AF8),
    define_vanilla_lvl_geo(castle_geo_001B48),
    define_vanilla_lvl_geo(castle_geo_001BB0),
    define_vanilla_lvl_geo(castle_geo_001C10),
    define_vanilla_lvl_geo(castle_grounds_geo_000660),
    define_vanilla_lvl_geo(castle_grounds_geo_0006F4),
    define_vanilla_lvl_geo(castle_grounds_geo_00070C),
    define_vanilla_lvl_geo(castle_grounds_geo_000724),
    define_vanilla_lvl_geo(castle_grounds_geo_00073C),
    define_vanilla_lvl_geo(ccm_geo_0003D0),
    define_vanilla_lvl_geo(ccm_geo_0003F0),
    define_vanilla_lvl_geo(ccm_geo_00040C),
    define_vanilla_lvl_geo(ccm_geo_00042C),
    define_vanilla_lvl_geo(ccm_geo_00045C),
    define_vanilla_lvl_geo(ccm_geo_000494),
    define_vanilla_lvl_geo(ccm_geo_0004BC),
    define_vanilla_lvl_geo(ccm_geo_0004E4),
    define_vanilla_lvl_geo(ccm_geo_00051C),
    define_vanilla_lvl_geo(ccm_geo_0005E8),
    define_vanilla_lvl_geo(ddd_geo_000450),
    define_vanilla_lvl_geo(ddd_geo_000478),
    define_vanilla_lvl_geo(ddd_geo_0004A0),
    define_vanilla_lvl_geo(ddd_geo_0004C0),
    define_vanilla_lvl_geo(ddd_geo_000570),
    define_vanilla_lvl_geo(geo_bbh_0005B0),
    define_vanilla_lvl_geo(geo_bbh_0005C8),
    define_vanilla_lvl_geo(geo_bbh_0005E0),
    define_vanilla_lvl_geo(geo_bbh_0005F8),
    define_vanilla_lvl_geo(geo_bbh_000610),
    define_vanilla_lvl_geo(geo_bbh_000628),
    define_vanilla_lvl_geo(geo_bbh_000640),
    define_vanilla_lvl_geo(geo_bbh_000658),
    define_vanilla_lvl_geo(geo_bbh_000670),
    define_vanilla_lvl_geo(geo_bbh_0006B0),
    define_vanilla_lvl_geo(geo_bbh_0006E8),
    define_vanilla_lvl_geo(geo_bbh_000730),
    define_vanilla_lvl_geo(geo_bbh_000750),
    define_vanilla_lvl_geo(geo_bbh_000768),
    define_vanilla_lvl_geo(geo_bbh_0007B0),
    define_vanilla_lvl_geo(geo_bbh_0007D0),
    define_vanilla_lvl_geo(geo_bbh_000800),
    define_vanilla_lvl_geo(geo_bbh_000828),
    define_vanilla_lvl_geo(geo_bbh_000860),
    define_vanilla_lvl_geo(geo_bbh_000888),
    define_vanilla_lvl_geo(geo_bbh_0008B0),
    define_vanilla_lvl_geo(geo_bbh_0008E8),
    define_vanilla_lvl_geo(geo_bbh_000950),
    define_vanilla_lvl_geo(geo_bbh_0009C8),
    define_vanilla_lvl_geo(geo_bbh_000A18),
    define_vanilla_lvl_geo(geo_bbh_000A60),
    define_vanilla_lvl_geo(geo_bbh_000AD8),
    define_vanilla_lvl_geo(geo_bbh_000B28),
    define_vanilla_lvl_geo(geo_bbh_000B88),
    define_vanilla_lvl_geo(geo_bbh_000BF0),
    define_vanilla_lvl_geo(geo_bbh_000C38),
    define_vanilla_lvl_geo(geo_bbh_000C88),
    define_vanilla_lvl_geo(geo_bbh_000CE8),
    define_vanilla_lvl_geo(geo_bbh_000D20),
    define_vanilla_lvl_geo(geo_bbh_000D68),
    define_vanilla_lvl_geo(geo_bbh_000DB0),
    define_vanilla_lvl_geo(geo_bbh_000DF0),
    define_vanilla_lvl_geo(geo_bbh_000E40),
    define_vanilla_lvl_geo(geo_bbh_000E80),
    define_vanilla_lvl_geo(geo_bbh_000EB0),
    define_vanilla_lvl_geo(geo_bbh_000F00),
    define_vanilla_lvl_geo(geo_bitdw_0003C0),
    define_vanilla_lvl_geo(geo_bitdw_0003D8),
    define_vanilla_lvl_geo(geo_bitdw_0003F0),
    define_vanilla_lvl_geo(geo_bitdw_000408),
    define_vanilla_lvl_geo(geo_bitdw_000420),
    define_vanilla_lvl_geo(geo_bitdw_000438),
    define_vanilla_lvl_geo(geo_bitdw_000450),
    define_vanilla_lvl_geo(geo_bitdw_000468),
    define_vanilla_lvl_geo(geo_bitdw_000480),
    define_vanilla_lvl_geo(geo_bitdw_000498),
    define_vanilla_lvl_geo(geo_bitdw_0004B0),
    define_vanilla_lvl_geo(geo_bitdw_0004C8),
    define_vanilla_lvl_geo(geo_bitdw_0004E0),
    define_vanilla_lvl_geo(geo_bitdw_0004F8),
    define_vanilla_lvl_geo(geo_bitdw_000510),
    define_vanilla_lvl_geo(geo_bitdw_000528),
    define_vanilla_lvl_geo(geo_bitdw_000540),
    define_vanilla_lvl_geo(geo_bitdw_000558),
    define_vanilla_lvl_geo(geo_bitdw_000570),
    define_vanilla_lvl_geo(geo_bitdw_000588),
    define_vanilla_lvl_geo(geo_bitdw_0005A0),
    define_vanilla_lvl_geo(geo_bitdw_0005B8),
    define_vanilla_lvl_geo(geo_bitdw_0005D0),
    define_vanilla_lvl_geo(geo_bitdw_0005E8),
    define_vanilla_lvl_geo(geo_bitdw_000600),
    define_vanilla_lvl_geo(geo_bitdw_000618),
    define_vanilla_lvl_geo(hmc_geo_000530),
    define_vanilla_lvl_geo(hmc_geo_000548),
    define_vanilla_lvl_geo(hmc_geo_000570),
    define_vanilla_lvl_geo(hmc_geo_000588),
    define_vanilla_lvl_geo(hmc_geo_0005A0),
    define_vanilla_lvl_geo(hmc_geo_0005B8),
    define_vanilla_lvl_geo(hmc_geo_0005D0),
    define_vanilla_lvl_geo(hmc_geo_0005E8),
    define_vanilla_lvl_geo(hmc_geo_000618),
    define_vanilla_lvl_geo(hmc_geo_000658),
    define_vanilla_lvl_geo(hmc_geo_0006A8),
    define_vanilla_lvl_geo(hmc_geo_0006E0),
    define_vanilla_lvl_geo(hmc_geo_000700),
    define_vanilla_lvl_geo(hmc_geo_000748),
    define_vanilla_lvl_geo(hmc_geo_000770),
    define_vanilla_lvl_geo(hmc_geo_000798),
    define_vanilla_lvl_geo(hmc_geo_0007F8),
    define_vanilla_lvl_geo(hmc_geo_000850),
    define_vanilla_lvl_geo(hmc_geo_0008D0),
    define_vanilla_lvl_geo(hmc_geo_000938),
    define_vanilla_lvl_geo(hmc_geo_000998),
    define_vanilla_lvl_geo(hmc_geo_000A18),
    define_vanilla_lvl_geo(hmc_geo_000A88),
    define_vanilla_lvl_geo(hmc_geo_000AE8),
    define_vanilla_lvl_geo(hmc_geo_000B48),
    define_vanilla_lvl_geo(hmc_geo_000B90),
    define_vanilla_lvl_geo(jrb_geo_000900),
    define_vanilla_lvl_geo(jrb_geo_000918),
    define_vanilla_lvl_geo(jrb_geo_000930),
    define_vanilla_lvl_geo(jrb_geo_000948),
    define_vanilla_lvl_geo(jrb_geo_000960),
    define_vanilla_lvl_geo(jrb_geo_000978),
    define_vanilla_lvl_geo(jrb_geo_000990),
    define_vanilla_lvl_geo(jrb_geo_0009B0),
    define_vanilla_lvl_geo(jrb_geo_0009C8),
    define_vanilla_lvl_geo(jrb_geo_0009E8),
    define_vanilla_lvl_geo(jrb_geo_000A00),
    define_vanilla_lvl_geo(jrb_geo_000A18),
    define_vanilla_lvl_geo(jrb_geo_000AFC),
    define_vanilla_lvl_geo(lll_geo_0009E0),
    define_vanilla_lvl_geo(lll_geo_0009F8),
    define_vanilla_lvl_geo(lll_geo_000A10),
    define_vanilla_lvl_geo(lll_geo_000A28),
    define_vanilla_lvl_geo(lll_geo_000A40),
    define_vanilla_lvl_geo(lll_geo_000A60),
    define_vanilla_lvl_geo(lll_geo_000A78),
    define_vanilla_lvl_geo(lll_geo_000A90),
    define_vanilla_lvl_geo(lll_geo_000AA8),
    define_vanilla_lvl_geo(lll_geo_000AC0),
    define_vanilla_lvl_geo(lll_geo_000AD8),
    define_vanilla_lvl_geo(lll_geo_000AF0),
    define_vanilla_lvl_geo(lll_geo_000B08),
    define_vanilla_lvl_geo(lll_geo_000B20),
    define_vanilla_lvl_geo(lll_geo_000B38),
    define_vanilla_lvl_geo(lll_geo_000B50),
    define_vanilla_lvl_geo(lll_geo_000B68),
    define_vanilla_lvl_geo(lll_geo_000B80),
    define_vanilla_lvl_geo(lll_geo_000B98),
    define_vanilla_lvl_geo(lll_geo_000BB0),
    define_vanilla_lvl_geo(lll_geo_000BC8),
    define_vanilla_lvl_geo(lll_geo_000BE0),
    define_vanilla_lvl_geo(lll_geo_000BF8),
    define_vanilla_lvl_geo(lll_geo_000C10),
    define_vanilla_lvl_geo(lll_geo_000C30),
    define_vanilla_lvl_geo(lll_geo_000C50),
    define_vanilla_lvl_geo(lll_geo_000C70),
    define_vanilla_lvl_geo(lll_geo_000C90),
    define_vanilla_lvl_geo(lll_geo_000CB0),
    define_vanilla_lvl_geo(lll_geo_000CD0),
    define_vanilla_lvl_geo(lll_geo_000CF0),
    define_vanilla_lvl_geo(lll_geo_000D10),
    define_vanilla_lvl_geo(lll_geo_000D30),
    define_vanilla_lvl_geo(lll_geo_000D50),
    define_vanilla_lvl_geo(lll_geo_000D70),
    define_vanilla_lvl_geo(lll_geo_000D90),
    define_vanilla_lvl_geo(lll_geo_000DB0),
    define_vanilla_lvl_geo(lll_geo_000DD0),
    define_vanilla_lvl_geo(lll_geo_000DE8),
    define_vanilla_lvl_geo(lll_geo_000E00),
    define_vanilla_lvl_geo(lll_geo_000EA8),
    define_vanilla_lvl_geo(lll_geo_000EC0),
    define_vanilla_lvl_geo(pss_geo_000100),
    define_vanilla_lvl_geo(rr_geo_000660),
    define_vanilla_lvl_geo(rr_geo_000678),
    define_vanilla_lvl_geo(rr_geo_000690),
    define_vanilla_lvl_geo(rr_geo_0006A8),
    define_vanilla_lvl_geo(rr_geo_0006C0),
    define_vanilla_lvl_geo(rr_geo_0006D8),
    define_vanilla_lvl_geo(rr_geo_0006F0),
    define_vanilla_lvl_geo(rr_geo_000708),
    define_vanilla_lvl_geo(rr_geo_000720),
    define_vanilla_lvl_geo(rr_geo_000738),
    define_vanilla_lvl_geo(rr_geo_000758),
    define_vanilla_lvl_geo(rr_geo_000770),
    define_vanilla_lvl_geo(rr_geo_000788),
    define_vanilla_lvl_geo(rr_geo_0007A0),
    define_vanilla_lvl_geo(rr_geo_0007B8),
    define_vanilla_lvl_geo(rr_geo_0007D0),
    define_vanilla_lvl_geo(rr_geo_0007E8),
    define_vanilla_lvl_geo(rr_geo_000800),
    define_vanilla_lvl_geo(rr_geo_000818),
    define_vanilla_lvl_geo(rr_geo_000830),
    define_vanilla_lvl_geo(rr_geo_000848),
    define_vanilla_lvl_geo(rr_geo_000860),
    define_vanilla_lvl_geo(rr_geo_000878),
    define_vanilla_lvl_geo(rr_geo_000890),
    define_vanilla_lvl_geo(rr_geo_0008A8),
    define_vanilla_lvl_geo(rr_geo_0008C0),
    define_vanilla_lvl_geo(rr_geo_0008D8),
    define_vanilla_lvl_geo(rr_geo_0008F0),
    define_vanilla_lvl_geo(rr_geo_000908),
    define_vanilla_lvl_geo(rr_geo_000920),
    define_vanilla_lvl_geo(rr_geo_000940),
    define_vanilla_lvl_geo(rr_geo_000958),
    define_vanilla_lvl_geo(rr_geo_000970),
    define_vanilla_lvl_geo(rr_geo_000988),
    define_vanilla_lvl_geo(rr_geo_0009A0),
    define_vanilla_lvl_geo(rr_geo_0009B8),
    define_vanilla_lvl_geo(rr_geo_0009D0),
    define_vanilla_lvl_geo(sa_geo_000170),
    define_vanilla_lvl_geo(sl_geo_000360),
    define_vanilla_lvl_geo(sl_geo_000378),
    define_vanilla_lvl_geo(sl_geo_000390),
    define_vanilla_lvl_geo(sl_geo_0003A8),
    define_vanilla_lvl_geo(sl_geo_000484),
    define_vanilla_lvl_geo(ssl_geo_0005C0),
    define_vanilla_lvl_geo(ssl_geo_0005D8),
    define_vanilla_lvl_geo(ssl_geo_000618),
    define_vanilla_lvl_geo(ssl_geo_000630),
    define_vanilla_lvl_geo(ssl_geo_000648),
    define_vanilla_lvl_geo(ssl_geo_000734),
    define_vanilla_lvl_geo(ssl_geo_000764),
    define_vanilla_lvl_geo(ssl_geo_000794),
    define_vanilla_lvl_geo(ssl_geo_0007AC),
    define_vanilla_lvl_geo(ssl_geo_0007CC),
    define_vanilla_lvl_geo(ssl_geo_00088C),
    define_vanilla_lvl_geo(thi_geo_0005B0),
    define_vanilla_lvl_geo(thi_geo_0005C8),
    define_vanilla_lvl_geo(thi_geo_0005F0),
    define_vanilla_lvl_geo(thi_geo_000608),
    define_vanilla_lvl_geo(thi_geo_0006D4),
    define_vanilla_lvl_geo(thi_geo_00079C),
    define_vanilla_lvl_geo(totwc_geo_000160),
    define_vanilla_lvl_geo(totwc_geo_000188),
    define_vanilla_lvl_geo(ttc_geo_000240),
    define_vanilla_lvl_geo(ttc_geo_000258),
    define_vanilla_lvl_geo(ttc_geo_000270),
    define_vanilla_lvl_geo(ttc_geo_000288),
    define_vanilla_lvl_geo(ttc_geo_0002A8),
    define_vanilla_lvl_geo(ttc_geo_0002C8),
    define_vanilla_lvl_geo(ttc_geo_0002E0),
    define_vanilla_lvl_geo(ttc_geo_0002F8),
    define_vanilla_lvl_geo(ttc_geo_000310),
    define_vanilla_lvl_geo(ttc_geo_000328),
    define_vanilla_lvl_geo(ttc_geo_000340),
    define_vanilla_lvl_geo(ttc_geo_000358),
    define_vanilla_lvl_geo(ttc_geo_000370),
    define_vanilla_lvl_geo(ttc_geo_000388),
    define_vanilla_lvl_geo(ttc_geo_0003A0),
    define_vanilla_lvl_geo(ttc_geo_0003B8),
    define_vanilla_lvl_geo(ttm_geo_000710),
    define_vanilla_lvl_geo(ttm_geo_000730),
    define_vanilla_lvl_geo(ttm_geo_000748),
    define_vanilla_lvl_geo(ttm_geo_000778),
    define_vanilla_lvl_geo(ttm_geo_0007A8),
    define_vanilla_lvl_geo(ttm_geo_0007D8),
    define_vanilla_lvl_geo(ttm_geo_000808),
    define_vanilla_lvl_geo(ttm_geo_000830),
    define_vanilla_lvl_geo(ttm_geo_000858),
    define_vanilla_lvl_geo(ttm_geo_000880),
    define_vanilla_lvl_geo(ttm_geo_0008A8),
    define_vanilla_lvl_geo(ttm_geo_0008D0),
    define_vanilla_lvl_geo(ttm_geo_0008F8),
    define_vanilla_lvl_geo(ttm_geo_000920),
    define_vanilla_lvl_geo(ttm_geo_000948),
    define_vanilla_lvl_geo(ttm_geo_000970),
    define_vanilla_lvl_geo(ttm_geo_000990),
    define_vanilla_lvl_geo(ttm_geo_0009C0),
    define_vanilla_lvl_geo(ttm_geo_0009F0),
    define_vanilla_lvl_geo(ttm_geo_000A18),
    define_vanilla_lvl_geo(ttm_geo_000A40),
    define_vanilla_lvl_geo(ttm_geo_000A70),
    define_vanilla_lvl_geo(ttm_geo_000B5C),
    define_vanilla_lvl_geo(ttm_geo_000BEC),
    define_vanilla_lvl_geo(ttm_geo_000C84),
    define_vanilla_lvl_geo(ttm_geo_000D14),
    define_vanilla_lvl_geo(ttm_geo_000D4C),
    define_vanilla_lvl_geo(ttm_geo_000D84),
    define_vanilla_lvl_geo(ttm_geo_000DBC),
    define_vanilla_lvl_geo(ttm_geo_000DF4),
    define_vanilla_lvl_geo(vcutm_geo_0001F0),
    define_vanilla_lvl_geo(vcutm_geo_000208),
    define_vanilla_lvl_geo(wdw_geo_000580),
    define_vanilla_lvl_geo(wdw_geo_000598),
    define_vanilla_lvl_geo(wdw_geo_0005C0),
    define_vanilla_lvl_geo(wdw_geo_0005E8),
    define_vanilla_lvl_geo(wdw_geo_000610),
    define_vanilla_lvl_geo(wdw_geo_000628),
    define_vanilla_lvl_geo(wdw_geo_000640),
    define_vanilla_lvl_geo(wdw_geo_000658),
    define_vanilla_lvl_geo(wdw_geo_000724),
    define_vanilla_lvl_geo(wf_geo_0007E0),
    define_vanilla_lvl_geo(wf_geo_000820),
    define_vanilla_lvl_geo(wf_geo_000860),
    define_vanilla_lvl_geo(wf_geo_000878),
    define_vanilla_lvl_geo(wf_geo_000890),
    define_vanilla_lvl_geo(wf_geo_0008A8),
    define_vanilla_lvl_geo(wf_geo_0008E8),
    define_vanilla_lvl_geo(wf_geo_000900),
    define_vanilla_lvl_geo(wf_geo_000940),
    define_vanilla_lvl_geo(wf_geo_000958),
    define_vanilla_lvl_geo(wf_geo_0009A0),
    define_vanilla_lvl_geo(wf_geo_0009B8),
    define_vanilla_lvl_geo(wf_geo_0009D0),
    define_vanilla_lvl_geo(wf_geo_0009E8),
    define_vanilla_lvl_geo(wf_geo_000A00),
    define_vanilla_lvl_geo(wf_geo_000A40),
    define_vanilla_lvl_geo(wf_geo_000A58),
    define_vanilla_lvl_geo(wf_geo_000A98),
    define_vanilla_lvl_geo(wf_geo_000AB0),
    define_vanilla_lvl_geo(wf_geo_000AC8),
    define_vanilla_lvl_geo(wf_geo_000AE0),
    define_vanilla_lvl_geo(wf_geo_000AF8),
    define_vanilla_lvl_geo(wf_geo_000B10),
    define_vanilla_lvl_geo(wf_geo_000B38),
    define_vanilla_lvl_geo(wf_geo_000B60),
    define_vanilla_lvl_geo(wf_geo_000B78),
    define_vanilla_lvl_geo(wf_geo_000B90),
    define_vanilla_lvl_geo(wf_geo_000BA8),
    define_vanilla_lvl_geo(wf_geo_000BC8),
    define_vanilla_lvl_geo(wf_geo_000BE0),
    define_vanilla_lvl_geo(wf_geo_000BF8),
    define_vanilla_lvl_geo(wmotr_geo_0001F0),
};

const GeoLayout* DynOS_Mgr_VanillaLvlGeo_GetFromName(const char* aDataName) {
    MGR_FIND_DATA(sDynosVanillaLvlGeos, (const GeoLayout*));
}

const char* DynOS_Mgr_VanillaLvlGeo_GetFromData(const GeoLayout* aData) {
    MGR_FIND_NAME(sDynosVanillaLvlGeos);
}

  //////////////
 // Textures //
//////////////

#define define_vanilla_tex(tex) (const void*) #tex, (const void*) tex
static const void* sDynosVanillaTexs[] = {
    define_vanilla_tex(cave_09000000),
    define_vanilla_tex(cave_09001000),
    define_vanilla_tex(cave_09001800),
    define_vanilla_tex(cave_09002800),
    define_vanilla_tex(cave_09003000),
    define_vanilla_tex(cave_09003800),
    define_vanilla_tex(cave_09004800),
    define_vanilla_tex(cave_09005800),
    define_vanilla_tex(cave_09006800),
    define_vanilla_tex(cave_09007000),
    define_vanilla_tex(cave_09007800),
    define_vanilla_tex(cave_09008800),
    define_vanilla_tex(cave_09009800),
    define_vanilla_tex(cave_0900A000),
    define_vanilla_tex(cave_0900A800),
    define_vanilla_tex(cave_0900B800),
    define_vanilla_tex(cave_0900C000),
    define_vanilla_tex(fire_09000000),
    define_vanilla_tex(fire_09000800),
    define_vanilla_tex(fire_09001000),
    define_vanilla_tex(fire_09001800),
    define_vanilla_tex(fire_09002000),
    define_vanilla_tex(fire_09002800),
    define_vanilla_tex(fire_09003000),
    define_vanilla_tex(fire_09003800),
    define_vanilla_tex(fire_09004000),
    define_vanilla_tex(fire_09004800),
    define_vanilla_tex(fire_09005000),
    define_vanilla_tex(fire_09005800),
    define_vanilla_tex(fire_09006000),
    define_vanilla_tex(fire_09006800),
    define_vanilla_tex(fire_09007000),
    define_vanilla_tex(fire_09007800),
    define_vanilla_tex(fire_09008000),
    define_vanilla_tex(fire_09008800),
    define_vanilla_tex(fire_09009000),
    define_vanilla_tex(fire_09009800),
    define_vanilla_tex(fire_0900A000),
    define_vanilla_tex(fire_0900A800),
    define_vanilla_tex(fire_0900B000),
    define_vanilla_tex(fire_0900B800),
    define_vanilla_tex(generic_09000000),
    define_vanilla_tex(generic_09000800),
    define_vanilla_tex(generic_09001000),
    define_vanilla_tex(generic_09001800),
    define_vanilla_tex(generic_09002000),
    define_vanilla_tex(generic_09002800),
    define_vanilla_tex(generic_09003000),
    define_vanilla_tex(generic_09003800),
    define_vanilla_tex(generic_09004000),
    define_vanilla_tex(generic_09004800),
    define_vanilla_tex(generic_09005000),
    define_vanilla_tex(generic_09005800),
    define_vanilla_tex(generic_09006000),
    define_vanilla_tex(generic_09007000),
    define_vanilla_tex(generic_09007800),
    define_vanilla_tex(generic_09008000),
    define_vanilla_tex(generic_09008800),
    define_vanilla_tex(generic_09009000),
    define_vanilla_tex(generic_09009800),
    define_vanilla_tex(generic_0900A000),
    define_vanilla_tex(generic_0900A800),
    define_vanilla_tex(generic_0900B000),
    define_vanilla_tex(grass_09000000),
    define_vanilla_tex(grass_09000800),
    define_vanilla_tex(grass_09001000),
    define_vanilla_tex(grass_09001800),
    define_vanilla_tex(grass_09002000),
    define_vanilla_tex(grass_09002800),
    define_vanilla_tex(grass_09003000),
    define_vanilla_tex(grass_09003800),
    define_vanilla_tex(grass_09004000),
    define_vanilla_tex(grass_09004800),
    define_vanilla_tex(grass_09005000),
    define_vanilla_tex(grass_09005800),
    define_vanilla_tex(grass_09006000),
    define_vanilla_tex(grass_09006800),
    define_vanilla_tex(grass_09007000),
    define_vanilla_tex(grass_09007800),
    define_vanilla_tex(grass_09008000),
    define_vanilla_tex(grass_09008800),
    define_vanilla_tex(grass_09009000),
    define_vanilla_tex(grass_09009800),
    define_vanilla_tex(grass_0900A000),
    define_vanilla_tex(grass_0900A800),
    define_vanilla_tex(grass_0900B000),
    define_vanilla_tex(grass_0900B800),
    define_vanilla_tex(inside_09000000),
    define_vanilla_tex(inside_09001000),
    define_vanilla_tex(inside_09002000),
    define_vanilla_tex(inside_09003000),
    define_vanilla_tex(inside_09003800),
    define_vanilla_tex(inside_09004000),
    define_vanilla_tex(inside_09004800),
    define_vanilla_tex(inside_09005000),
    define_vanilla_tex(inside_09005800),
    define_vanilla_tex(inside_09006000),
    define_vanilla_tex(inside_09007000),
    define_vanilla_tex(inside_09008000),
    define_vanilla_tex(inside_09008800),
    define_vanilla_tex(inside_09009000),
    define_vanilla_tex(inside_0900A000),
    define_vanilla_tex(inside_0900B000),
    define_vanilla_tex(inside_0900B800),
    define_vanilla_tex(machine_09000000),
    define_vanilla_tex(machine_09000800),
    define_vanilla_tex(machine_09001000),
    define_vanilla_tex(machine_09001800),
    define_vanilla_tex(machine_09002000),
    define_vanilla_tex(machine_09002800),
    define_vanilla_tex(machine_09003000),
    define_vanilla_tex(machine_09003800),
    define_vanilla_tex(machine_09004000),
    define_vanilla_tex(machine_09005000),
    define_vanilla_tex(machine_09005800),
    define_vanilla_tex(machine_09006000),
    define_vanilla_tex(machine_09006800),
    define_vanilla_tex(machine_09007000),
    define_vanilla_tex(machine_09007800),
    define_vanilla_tex(machine_09008000),
    define_vanilla_tex(machine_09008400),
    define_vanilla_tex(mountain_09000000),
    define_vanilla_tex(mountain_09000800),
    define_vanilla_tex(mountain_09001800),
    define_vanilla_tex(mountain_09002800),
    define_vanilla_tex(mountain_09003000),
    define_vanilla_tex(mountain_09003800),
    define_vanilla_tex(mountain_09004000),
    define_vanilla_tex(mountain_09004800),
    define_vanilla_tex(mountain_09005000),
    define_vanilla_tex(mountain_09005800),
    define_vanilla_tex(mountain_09006800),
    define_vanilla_tex(mountain_09007000),
    define_vanilla_tex(mountain_09007800),
    define_vanilla_tex(mountain_09008000),
    define_vanilla_tex(mountain_09008800),
    define_vanilla_tex(mountain_09009800),
    define_vanilla_tex(mountain_0900A000),
    define_vanilla_tex(mountain_0900A800),
    define_vanilla_tex(mountain_0900B000),
    define_vanilla_tex(mountain_0900B800),
    define_vanilla_tex(mountain_0900C000),
    define_vanilla_tex(outside_09000000),
    define_vanilla_tex(outside_09000800),
    define_vanilla_tex(outside_09001000),
    define_vanilla_tex(outside_09002000),
    define_vanilla_tex(outside_09003000),
    define_vanilla_tex(outside_09003800),
    define_vanilla_tex(outside_09004000),
    define_vanilla_tex(outside_09004800),
    define_vanilla_tex(outside_09005800),
    define_vanilla_tex(outside_09006000),
    define_vanilla_tex(outside_09006800),
    define_vanilla_tex(outside_09007800),
    define_vanilla_tex(outside_09008000),
    define_vanilla_tex(outside_09008800),
    define_vanilla_tex(outside_09009000),
    define_vanilla_tex(outside_09009800),
    define_vanilla_tex(outside_0900A000),
    define_vanilla_tex(outside_0900A800),
    define_vanilla_tex(outside_0900B000),
    define_vanilla_tex(outside_0900B400),
    define_vanilla_tex(outside_0900BC00),
    define_vanilla_tex(sky_09000000),
    define_vanilla_tex(sky_09000800),
    define_vanilla_tex(sky_09001000),
    define_vanilla_tex(sky_09001800),
    define_vanilla_tex(sky_09002000),
    define_vanilla_tex(sky_09003000),
    define_vanilla_tex(sky_09003800),
    define_vanilla_tex(sky_09004800),
    define_vanilla_tex(sky_09005000),
    define_vanilla_tex(sky_09005800),
    define_vanilla_tex(sky_09006000),
    define_vanilla_tex(texture_metal_hole),
    define_vanilla_tex(sky_09007000),
    define_vanilla_tex(sky_09007800),
    define_vanilla_tex(sky_09008000),
    define_vanilla_tex(snow_09000000),
    define_vanilla_tex(snow_09000800),
    define_vanilla_tex(snow_09001000),
    define_vanilla_tex(snow_09002000),
    define_vanilla_tex(snow_09002800),
    define_vanilla_tex(snow_09003000),
    define_vanilla_tex(snow_09003800),
    define_vanilla_tex(snow_09004000),
    define_vanilla_tex(snow_09004800),
    define_vanilla_tex(snow_09005000),
    define_vanilla_tex(snow_09005800),
    define_vanilla_tex(snow_09006000),
    define_vanilla_tex(snow_09006800),
    define_vanilla_tex(snow_09007000),
    define_vanilla_tex(snow_09008000),
    define_vanilla_tex(snow_09008800),
    define_vanilla_tex(snow_09009000),
    define_vanilla_tex(snow_09009800),
    define_vanilla_tex(spooky_09000000),
    define_vanilla_tex(spooky_09000800),
    define_vanilla_tex(spooky_09001800),
    define_vanilla_tex(spooky_09002800),
    define_vanilla_tex(spooky_09003800),
    define_vanilla_tex(spooky_09004800),
    define_vanilla_tex(spooky_09005000),
    define_vanilla_tex(spooky_09006000),
    define_vanilla_tex(spooky_09006800),
    define_vanilla_tex(spooky_09007000),
    define_vanilla_tex(spooky_09008000),
    define_vanilla_tex(spooky_09008800),
    define_vanilla_tex(spooky_09009000),
    define_vanilla_tex(spooky_0900A000),
    define_vanilla_tex(spooky_0900A800),
    define_vanilla_tex(spooky_0900B000),
    define_vanilla_tex(spooky_0900B800),
    define_vanilla_tex(water_09000000),
    define_vanilla_tex(water_09000800),
    define_vanilla_tex(water_09001800),
    define_vanilla_tex(water_09002800),
    define_vanilla_tex(water_09003800),
    define_vanilla_tex(water_09004800),
    define_vanilla_tex(water_09005800),
    define_vanilla_tex(water_09006000),
    define_vanilla_tex(water_09006800),
    define_vanilla_tex(water_09007800),
    define_vanilla_tex(water_09008800),
    define_vanilla_tex(water_09009000),
    define_vanilla_tex(water_0900A000),
    define_vanilla_tex(water_0900A800),
    define_vanilla_tex(water_0900B800),
};

const Texture* DynOS_Mgr_VanillaTex_GetFromName(const char* aDataName) {
    MGR_FIND_DATA(sDynosVanillaTexs, (const Texture*));
}

const char* DynOS_Mgr_VanillaTex_GetFromData(const Texture* aData) {
    MGR_FIND_NAME(sDynosVanillaTexs);
}
