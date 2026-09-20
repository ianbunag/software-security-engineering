#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main (void)
{
    char choice[4];
    int sandwich_cost=0;
    puts("Choice of sandwich: a.RoastBeef:6, b.Tuna:5,  c.Turkey:4");
    scanf("%s",choice);
    if (choice[0] == 'a')
        sandwich_cost=6;
    else if (choice[0] == 'b')
        sandwich_cost=5;
    else if (choice[0] == 'c')
        sandwich_cost=4;

    int drink_cost=0;
    puts("Choice of drink: a.Coke:3, b.Milk:2,  c.Water:1");
    scanf("%s",choice);
    if (choice[0] == 'a')
        drink_cost=3;
    else if (choice[0] == 'b')
        drink_cost=2;
    else if (choice[0] == 'c')
        drink_cost=1;

    char *customer_name = (char*)malloc(16);
    puts("Enter Name: ");
    scanf("%s",customer_name);
    int *balance = (int*)malloc(4);
    *balance += sandwich_cost+drink_cost;
    printf("%s, your balance is: %d\n",customer_name,*balance);
}
