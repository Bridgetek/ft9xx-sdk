/* Default linker script, for normal executables */
OUTPUT_FORMAT("elf32-ft32")
OUTPUT_ARCH(ft32)
SEARCH_DIR("/data/win8/ft32/ft32-elf/lib");

/* Allow the command line to override the memory region sizes.  */
__PMSIZE = DEFINED(__PMSIZE) ? __PMSIZE : DEFINED(__FT930__)? 128K : 256K;
__RAMSIZE = DEFINED(__RAMSIZE) ? __RAMSIZE : DEFINED(__FT930__)? 32K : 64K;

/* Allocate space reserved for bootloader */
__PROGMAX = __PMSIZE - 4K;
/* Allocate space reserved for D2XX configs */
__D2XX_PROG = __PROGMAX - 0x1000;
/* Allocate space reserved for DLOG configs */
__DLOG_PROG = __PROGMAX - 0x2000;

MEMORY
{
  /* Flash */
  flash       (rx)   : ORIGIN = 0          , LENGTH = __PROGMAX
  d2xx_cfg    (rx)   : ORIGIN = __D2XX_PROG, LENGTH = 4K
  dlog_cfg    (rx)   : ORIGIN = __DLOG_PROG, LENGTH = 4K
  bootflash   (rx)   : ORIGIN = __PROGMAX  , LENGTH = 4K

  /* RAM */
  ram         (rw!x) : ORIGIN = 0x800000, LENGTH = __RAMSIZE
  peripherals (rw!x) : ORIGIN = 0x810000, LENGTH = 0x1000
  ehci        (rw!x) : ORIGIN = 0x811000, LENGTH = 0x2000
}

SECTIONS
{
  .text :
  {
    *(.crt0*)
    *(.text*)
    *(.strings)
    *(._pm*)
    KEEP(*(SORT_NONE(.init)))
    KEEP(*(SORT_NONE(.fini)))
    . = ALIGN(16);
    _etext = . ;
    FILL(0xFF);
  } > flash

  .d2xx_configs __D2XX_PROG :
  {
    ___d2xx_cfg_start = .;
    . = ALIGN(4);
    KEEP(*(._flash_d2xx_config))
    . = ALIGN(4);
    ___d2xx_cfg_end = .;
    FILL(0xFF);
  } > d2xx_cfg

  .dlog_configs __DLOG_PROG :
  {
    . = ALIGN(4);
    KEEP(*(._flash_dlog_partition))
    . = ALIGN(4);
    FILL(0xFF);
  } > dlog_cfg

  .data :
  {
    . = ALIGN(4);
    __data = .;
    *(.data)
    *(.data*)
    *(.rodata)
    *(.rodata*)
    . = ALIGN(4);
    _edata = . ;
    FILL(0xFF);
  } > ram AT > flash

  .tors :
  {
    . = ALIGN(4);
    ___ctors = . ;
    *(.ctors)
    ___ctors_end = . ;
    ___dtors = . ;
    *(.dtors)
    . = ALIGN(4);
    ___dtors_end = . ;
  } > ram

  .bss SIZEOF(.data) + ADDR(.data) (NOLOAD) :
  {
    _bss_start = . ;
    *(.bss)
    *(COMMON)
    _end = . ;
  } > ram

  __data_load_start = LOADADDR(.data);
  __data_load_end   = __data_load_start + SIZEOF(.data);

  /* Peripheral Register Blocks from 0x810000 to 0x810FFF */
  .peripheralsBlock (NOLOAD):
  {
    KEEP(*(.peripheralsSection))
  } > peripherals

  /* EHCI RAM - Accessed via aligned 32 bit reads and writes only. */
  .ehciBlock (NOLOAD):
  {
    KEEP(*(.ehciSection))
  } > ehci

  .stab 0 (NOLOAD) :
  {
    *(.stab)
  }

  .stabstr 0 (NOLOAD) :
  {
    *(.stabstr)
  }

  .debug (NOLOAD) :
  {
    *(.debug*)
    *(.comment*)
  }
}
