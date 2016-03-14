#include <stdio.h>

#include <stdint.h>
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
#define ELFMAG0 0x7F
#define ELFMAG1 'E'
#define ELFMAG2 'L'
#define ELFMAG3 'F'

//File class
#define ELFCLASS32 1
#define EV_CURRENT 1
typedef uint32_t Elf_Word;
typedef uint16_t Elf_Half;
typedef uint32_t Elf32_Off;
typedef uint64_t Elf_Xword;
typedef uint32_t Elf32_Addr;
#define Elf32_Word Elf_Word
#define Elf32_Half Elf_Half

typedef struct {
    unsigned char e_ident[EI_NIDENT];
    Elf32_Word    e_version;
    Elf32_Half    e_ehsize;
    Elf32_Half    e_phentsize;
    Elf32_Half    e_shentsize;
} Elf32_ehdr;

typedef struct {
    Elf_Word p_type;
    Elf32_Off p_offset;
    Elf32_Addr p_vaddr;
    Elf32_Addr p_paddr;
    Elf32_Word p_filesz;
    Elf32_Word p_memsz; 
    Elf32_Word p_flags; 
    Elf32_Word p_align;
} Elf32_phdr;

typedef struct {
    Elf_Word sh_name;
    Elf_Word sh_type;
    Elf_Word sh_flags;
    Elf32_Addr sh_addr;
    Elf32_Off  sh_offset;
    Elf_Word sh_size;
    Elf_Word sh_link;
    Elf_Word sh_info;
    Elf_Word sh_addralign;
    Elf_Word sh_entsize;
} Elf32_shdr;

Elf32_ehdr create_header(unsigned char encoding)
{
    Elf32_ehdr header;

    header.e_ident[EI_MAG0] = ELFMAG0;
    header.e_ident[EI_MAG1] = ELFMAG1;
    header.e_ident[EI_MAG2] = ELFMAG2;
    header.e_ident[EI_MAG3] = ELFMAG3;
    header.e_ident[EI_CLASS] = ELFCLASS32;
    header.e_ident[EI_DATA] = encoding;
    header.e_ident[EI_VERSION] = EV_CURRENT;
    header.e_version = EV_CURRENT;
    header.e_ehsize = sizeof(header);
    header.e_phentsize = sizeof(Elf32_phdr);
    header.e_shentsize = sizeof(Elf32_shdr);
    printf("%d\n", header.e_ident[EI_MAG0]);
    printf("%d\n", header.e_ident[EI_MAG1]);
    printf("%d\n", header.e_ident[EI_MAG2]);
    printf("%d\n", header.e_ident[EI_MAG3]);
    printf("%d\n", header.e_ident[EI_CLASS]);
    printf("%d\n", header.e_ident[EI_DATA]);
    printf("%d\n", header.e_ident[EI_VERSION]);
    printf("%d\n", header.e_ehsize);
    printf("%d\n", header.e_phentsize);
    printf("%d\n", header.e_version);
    printf("%d\n", header.e_shentsize);
    return header;
}
void save(Elf32_ehdr *header)
{
   printf("this is the test\n");
   printf("%s\n", (char *)header);
   printf("%d\n", header->e_shentsize);
    FILE *elffile = fopen("elf.o", "wb");
    fwrite(header, sizeof(Elf32_ehdr), 1, elffile);
    close(elffile);
}

void elfcreator(unsigned char encoding)
{
    Elf32_ehdr header = create_header(encoding);
    save(&header);
}

