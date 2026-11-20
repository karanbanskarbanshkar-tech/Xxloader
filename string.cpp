String pack for anogs

//// 10 YEAR

gettimeofday ( crash fixer )

malloc ( 10 year offline )

close ( 10 year offline )

dlopen ( 10 year online )

realloc ( 10 year offline )
//// 1 DAY

memcpy ( 1 day online )

memset ( 1 day online )

memset_chk ( 1 day offline )

memcpy_chk ( 1 day offline )
//// REPORT

report

tdm_report

core report
//// TERMINATION

mktime
//// FLAG

NOT AVAILABLE
///////////
Make hook or use this hex
/x00/x00/x80/xD2/xC0/x03/x5F/xD6




IDA METHOD (PRIVATE - v4.6) 

// Offline/Runtime Fix'leri:
- memcpy_chk           // Dump & CRC fix (1-day ban prevention)
- __aeabi_memset       // Memory ban fix (10y)
- __strncpy_chk        // Crash fix (runtime)
- gmtime               // Time crash fix (year/month/sec issues)
- mktime               // Termination ban fix (10-30 min)
- gettimeofday         // Lobby crash fix
- strlen (EGL)         // EGL crash prevention
- imp.time             // Time-related crash fix
- dup2                 // File redirect fix (safe for 10 years)
- listen               // Socket hook fix (1-day ban prevention)
- calloc               // Heap integrity bypass (10y fix)
- realloc              // Stack/heap fix (10y memory fix)
- setuserinfo          // Match info user spoof

// Emulator / Integrity / Report Fix'leri:
- case 10              // Emulator detection skip
- case 16              // Crash fix case
- case 23              // Disable integrity check (permanent)
- case 35, 36, 49      // Fix -month ban detection
- case 38              // Fix termination
- All AnoSdk           // Report system bypass (anti-ban)
- {R4-R6, R10, R11, LR} // Ban fix via register NOP/stub patch

// Gelişmiş Bellek/Network Hook'ları:
- BX-LR                // Debug için offline method entry
- imp_recv, imp_send   // Packet hook için
- nanosleep            // Delay/anti-detection
- sys_open, sys_read   // File handle patch (anti-log)

void __fastcall *sub_1ECEA0(unsigned __int64 *a1)
{
while(true)

}

sleep(10000)

return 0;
}


__int64 __fastcall (*osub_22EAF4)(__int64 a1, __int64 a2, __int64 a3);
__int64 __fastcall hsub_22EAF4(__int64 a1, __int64 a2, __int64 a3)
{
    if ( (*(_BYTE *)(a2 + 68) & 1) == 1 )
        return 0; 
    
    return osub_22EAF4(a1, a2, a3);
}


sub_1DEC34
sub_200018
sub_2C839C
sub_385628
sub_4C7FE4
sub_4DFB80

sub_501AD4
sub_5026EC
sub_1C8D00
sub_251DE8
sub_425864

sub_252628
sub_267404
sub_26C648
sub_37B2FC
sub_4C7EF4
sub_5003A4

sub_320470
sub_3A564C

sub_4B202C
sub_501AD4
sub_506E2C
sub_50C584

sub_1C17E4
sub_1CEF44
sub_1F75CC
sub_2030F8
sub_2132E4

sub_1DDBF8
sub_1DED6C
sub_1EDE90
sub_1F7858
sub_1F97B4

sub_31F408
sub_3620A0
sub_446AD8

sub_20B8C4
sub_2F2D98
sub_493524
sub_4D1DD0
sub_4DA998



__int64 (*osub_31DCB0)(__int64 a1, __int64 a2, __int64 *a3);
__int64 hsub_31DCB0(__int64 a1, __int64 a2, __int64 *a3)
{
    if ( (*(_BYTE *)(a2 + 68) & 1) == 1 )
        return 0; 
    
    return osub_31DCB0(a1, a2, a3);
}

MemoryPatch::createWithHex("libanogs.so",0x228560,"C0 03 5F D6").Modify();//Case 37
MemoryPatch::createWithHex("libanogs.so",0x2ece70,"C0 03 5F D6").Modify();//10y
MemoryPatch::createWithHex("libanogs.so",0x213000,"00 00 80 D2 C0 03 5F D6").Modify();//crash Fixer
HOOK_LIB("libanogs.so", "0x31DCB0",hsub_31DCB0, osub_31DCB0);
PATCH_LIB("libUE4.so","0x7AD66F0","41 08 80 D2 41 00 00 B9 40 08 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x3A564C","00 00 80 D2 C0 03 5F D6");//Vtable
PATCH_LIB("libanogs.so","0x214098","C0 03 5F D6");
PATCH_LIB("libanogs.so","0x32165C","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x4FF680","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x4F7874","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x3DF4FC","00 00 80 D2 C0 03 5F D6");