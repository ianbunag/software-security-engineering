#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
    char stackBuffer[16];
    char *heapBuffer = (char*) malloc(16);
    strcpy(stackBuffer,"0123456789abcdef");
    strcpy(heapBuffer,"0123456789abcdef");
}
