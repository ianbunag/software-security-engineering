#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char subject[96];
char *body;
char *body1;
char *body2;
char *body3;
int matched;
int main (void)
{
    body1 = (char*) malloc(4096);
    puts("subject:");
    gets(subject);
    puts("body:");
    gets(body1);
    // do email processing here...
    puts("bye...");
}
