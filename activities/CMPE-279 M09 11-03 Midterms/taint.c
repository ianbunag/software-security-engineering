#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
    char* ip_address = argv[1]; /* Line 6: Direct tainted source */
    char cmd[128];
    strcpy(cmd, "ping -c 1 ");
    strcat(cmd, ip_address); /* Line 9: Transitive taint */
    system(cmd); /* Line 10: Sensitive sink */
    return 0;
}
