#include <stdio.h>
#include "elfgen.h"
#include <elf.h>
#define ELFDATA2LSB 1
int main()
{
    elfcreator(ELFDATA2LSB);
    return 0;
}
