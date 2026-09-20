#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
What is the problem with the above program?

The expected output is:
cp=foo here
cp2=bar here
cp=foo here

However, the actual output is:
cp=foo here
cp2=bar here
cp=bar here

This is caused by stack frame reuse. `fooBuffer` was allocated on the callStack and marked free after function `foo`
returns. `barBuffer` was then allocated on the exact same memory location that `fooBuffer` had and overwrote the
original string referenced by `cp`. This is fixed by allocating local variables referenced outside functions using
`malloc`, which allocates the frame on the heap and remains unreleased until freed by the caller.
 */

char* foo(void)
{
    char *fooBuffer = malloc(256);
    char *fooptr = fooBuffer;
    strcpy(fooBuffer,"foo here");
    return fooptr;
}
char* bar(void)
{
    char *barBuffer = malloc(256);
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
    free(cp);
    free(cp2);
}
