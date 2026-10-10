#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

struct item
{
    char name[16];
    int cost;
    int count;
};

struct item itemlist[] = {
    {"milk     ", 5, 0},
    {"eggs     ", 8, 0},
    {"juice    ", 6, 0},
    {"bread    ", 4, 0},
    {"ham      ", 7, 0},
    {"checkout ", 0, 0},
};
char* label[4] = {"no", "description", "cost", "count"};
int balance = 0;

int main(int argc, char* argv[])
{
    int i, choice, number;
    char buf[80];

    for (i = 0; i < 4; i++)
        printf("%s ", label[i]);
    printf("\n");
    for (i = 0; i < sizeof(itemlist) / sizeof(struct item); i++)
        printf("%d:%s        $%d       %d\n", i, itemlist[i].name, itemlist[i].cost, itemlist[i].count);

    while (1)
    {
        puts("choose item and count");
        scanf("%d", &choice);
        if (choice >= (sizeof(itemlist) / sizeof(struct item)))
        {
            puts("Invalid item number, please re-enter...");
            continue;
        }
        if (choice == sizeof(itemlist) / sizeof(struct item) - 1)
        {
            if (balance > 0)
                printf("Your balance is %d\n", balance);
            else
                printf("Your credit is %d\n", -balance);
            exit(0);
        }
        scanf("%d", &number);
        if (number <= 0)
        {
            puts("Invalid count, please re-enter...");
            continue;
        }
        /**
         * Validate that item cost does not exceed maximum int value.
         *
         * Test with:
         * $ 3
         * $ 1000000000
         */
        if (itemlist[choice].cost > 0 && number > INT_MAX / itemlist[choice].cost)
        {
            puts("Invalid count, please re-enter...");
            continue;
        }
        int item_total = number * itemlist[choice].cost;
        /**
         * Validate that balance does not exceed maximum int value when item cost is added.
         *
         * Test with:
         * $ 0
         * $ 429496729
         * $ 0
         * $ 1
         */
        if (INT_MAX - balance < item_total)
        {
            puts("Invalid count, please re-enter...");
            continue;
        }
        itemlist[choice].count = number;
        balance += item_total;
        for (i = 0; i < 4; i++)
            printf("%s ", label[i]);
        printf("\n");
        for (i = 0; i < sizeof(itemlist) / sizeof(struct item); i++)
            printf("%d:%s        $%d       %d\n", i, itemlist[i].name, itemlist[i].cost, itemlist[i].count);
        printf("balance:$%d\n", balance);
    }
    return 0;
}
