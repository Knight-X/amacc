#include <stdio.h>

#define EI_MAG0         0  
#define EI_MAG1         1
#define EI_MAG2         2
#define EI_MAG3         3
#define EI_CLASS        4
#define EI_DATA         5
#define EI_VERSION      6
#define EI_OSABI        7
#define EI_ABIVERSION   8
#define EI_PAD          9
#define EI_NIDENT       16

//File class
#define ELFCLASS32 1

struct Elf32_Ehdr{
    unsigned char e_ident[EI_NIDENT];
    Elf_Half      e_type;
    Elf32_Half    e_machine;
    Elf32_Word    e_version;
    Elf32_Addr    e_entry;
    Elf32_Off     e_phoff;
    Elf32_Off     e_shoff;
    Elf32_Word    e_flags;
    Elf32_Half    e_ehsize;
    Elf32_Half    e_phentsize;
    Elf32_Half    e_phnum;
    Elf32_Half    e_shentsize;
    Elf32_Half    e_shnum;
    Elf32_Half    e_shstrndx;
} Elf32_Ehdr;

Elf32_Ehdr create_header(unsigned char encoding)
{
    Elf32_Ehdr header;

    header.e_ident[EI_MAG0] = ELFMAG0;
    header.e_ident[EI_MAG1] = ELFMAG1;
    header.e_ident[EI_MAG2] = ELFMAG2;
    header.e_ident[EI_MAG3] = ELFMAG3;
    header.e_ident[EI_CLASS] = ELFCLASS32;
    header.e_ident[EI_DATA] = encoding;
    header.e_ident[EI_VERSION] = EV_CURRENT;
    header.e_version = EV_CURRENT;
    header.e_ehsize = sizeof(header);
    header.e_ehsize = (Elf_Half)1;
    header.e_phentsize = sizeof(Elf32_Phdr);
    header.e_shentsize = sizeof(Elf32_Shdr);

    return header;
}

}
void elfcreator(unsigned char encoding)
{
    Elf32_Ehdr header = create_header(encoding);
}

void save(Elf32_Ehdr header)
{
    
    FILE *elffile = fopen("elf.o", "r");

    elffile = fprintf(elffile, "%s", (const char *)header);

    elffile.close();
}
