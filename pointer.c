#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

#define BANK 0x4000

char *rom_name = "Super Mario Land (World).gb";

void main(void) {
  FILE *rom;
  
  int lev_num;
  int blk_num;
  
  unsigned int hl;
  
  rom = fopen(rom_name, "r");
  if(!rom) { puts("ROM"); return; }
  
  lev_num = 0;
  blk_num = 3;
  
  fseek(rom, BANK*2 + 2*lev_num, SEEK_SET);
  hl = 0;
  fread(&hl, 2, 1, rom);
  
  printf("%04x\n", hl);
  
  fseek(rom, BANK + hl, SEEK_SET);
  hl = 0;
  fread(&hl, 2, 1, rom);
  
  printf("%04x\n", hl);
  
  puts("done");
}
