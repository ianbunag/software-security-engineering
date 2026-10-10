#include <limits.h>
#include <stdio.h>
#include "ovfSubtract.h"

int main()
{
    int res;

    int x = 0;
    int y = INT_MIN;

    int overflow = ovfSubtract(&res, x, y);

    if (overflow == -1)
        printf("Integer Overflow detected");
    else
        printf("Integer Overflow not detected");

    printf("\n The Difference of x and y is: %d\n", res);

    return 0;
}
