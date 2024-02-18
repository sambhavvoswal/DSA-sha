#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stacklladt.h"

int main()
{
    int n, temp;
    int *pd;
    STACK *phead;
    bool res;

    phead = (STACK *)createstack();
    printf("enter the decimal number\n");
    scanf("%d", &n);
    temp = n;

    while (temp)
    {
        pd = (int *)malloc(sizeof(int));
        *pd = temp % 2;
        res = pushstack(phead, pd);
        temp = temp / 2;
    }

    printf("binary number of %d:\n", n);
    pd = (int *)popstack(phead);
    while (pd)
    {
        printf("%d\n", *pd);
        free(pd);
        pd = (int *)popstack(phead); // Move to the next element in the stack
    }

    destroystack(phead);
    return 0;
}
