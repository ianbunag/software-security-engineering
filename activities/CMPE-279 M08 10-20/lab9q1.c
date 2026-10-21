#include <stdio.h>
#include <string.h>
char password[16];
char passcode[16];
char input1[16];
char input2[16];
int main()
{
    strcpy(password,"santaclara");
    strcpy(passcode,"95053");
    printf("enter password:");
    scanf("%s",input1);
    if (strcmp(input1,password)==0) {
        printf("you guessed right!\n");
        return 0;
    }
    else {
        printf("Wrong password, lets try passcode, ");
        printf("enter passcode:");
        scanf("%s",input2);
        if (strcmp(input2,passcode)==0) {
            printf("you guessed right!\n");
            return 0;
        }
    }
    printf("you guessed wrong!\n");
}
