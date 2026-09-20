#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
What is the problem with the above program?
*/

char* foo(void)
{
    char fooBuffer[256];
    char *fooptr = fooBuffer;
    strcpy(fooBuffer,"foo here");
    return fooptr;
}
char* bar(void)
{
    char barBuffer[256];
    char *barptr = barBuffer;
    strcpy(barBuffer,"bar here");
    return barptr;
}
int main (void)
{
    char *cp,*cp2;
    cp = foo();
    printf("cp=%s\n",cp);
    cp2 = bar();
    printf("cp2=%s\n",cp2);
    printf("cp=%s\n",cp);
}
