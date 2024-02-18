#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stacklladt.h"

int main()
{
    int *pd;
    int data;
    STACK *phead;
    bool res;

    phead = (STACK *)createstack();
    printf("enter the data (enter a non-integer to finish)\n");

    while (scanf("%d", &data) == 1 || !stackfull(phead))
    {
        pd = (int *)malloc(sizeof(int));
        *pd = data;
        res = pushstack(phead, pd);

        if (!res)
        {
            printf("Stack is full. Exiting...\n");
            break;
        }
    }

    printf("reversed list of number series\n");

    pd = (int *)popstack(phead);

    while (pd)
    {
        printf("%3d   ", *pd);
        free(pd);
        pd = (int *)popstack(phead);
    }

    destroystack(phead);
    return 0;
}
