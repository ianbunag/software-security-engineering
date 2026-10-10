#include "ovfSubtract.h"

int ovfSubtract(int* result, const int x, const int y)
{
    *result = x - y;

    // (+x) - (-y) = (+z)
    // (0) - (INT_MIN) = (INT_MAX + 1)
    if (x >= 0 && y < 0 && *result < 0)
        return -1;
    // (-x) - (+y) = (-z)
    if (x < 0 && y > 0 && *result > 0)
        return -1;

    return 0;
}
