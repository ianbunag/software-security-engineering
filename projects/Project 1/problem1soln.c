#include <stdio.h>
#include <string.h>
int a1[5];
int a4[8][8];

int main()
{
    // using printf format %p to print the address
    printf("a1 %p\n", &a1[0]);
    printf("a4 %p\n", &a4[0][0]);

    a1[0] = 8;
    /*
      Add code below this comment that looks like:

      a1[something] = 8;
    */
    static int offset[17] = {8, 15, 17, 22, 26, 29, 35, 36, 43, 44, 51, 53, 57, 62, 64, 71};
    for (int i = 0; i < sizeof(offset); i++)
    {
        a1[offset[i]] = 8;
    }

    printf("a1[]=%d,%d,%d,%d,%d\n", a1[0], a1[1], a1[2], a1[3], a1[4]);
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            printf("%d,", a4[i][j]);
        printf("\n");
    }
}
