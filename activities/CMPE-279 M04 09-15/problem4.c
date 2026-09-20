#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* foo(void)
{
    char *ptr = malloc(128);
    strcpy(ptr,"a string");
    printf("%s\n",ptr);
    return ptr;
}
int main (void)
{
    char *cp;
    cp = foo();
}
