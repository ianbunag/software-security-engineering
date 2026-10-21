#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* foo()
{
    char buff[80];
    char *ptr = &buff[0];
    strcpy(ptr,"foo");
    return ptr;
}
char* bar()
{
    char *ptr = (char*) malloc(20);
    strcpy(ptr,"bar");
    return ptr;
}
int main()
{
    char buff1[10];
    strcpy(buff1,"california");
    char *buff2 = (char*) malloc(10);
    strcpy(buff2,"california");
    char *ptr = foo();
    char *ptr2 = bar();
    free(ptr2);
    strcpy(ptr2,"oregon");
}
