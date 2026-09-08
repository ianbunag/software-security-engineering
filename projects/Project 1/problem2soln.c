#include <stdio.h>
#include <string.h>
char uinput[16];
char pinput[16];
char password[16];
char userid[16];

int main()
{
    strcpy(password, "santaclara");
    strcpy(userid, "12345");
    do
    {
        printf("enter userid:");
        scanf("%s", uinput);
        if (strcmp(uinput, userid) == 0)
            break;
        printf("userid incorrect, try again\n");
    }
    while (1);
    do
    {
        printf("enter password:");
        scanf("%s", pinput);
        if (strcmp(pinput, password) == 0)
            break;
        printf("password incorrect, try again\n");
    }
    while (1);
    printf("Success!\n");
}
