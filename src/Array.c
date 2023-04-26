#include "../include/Array.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
pArr initArr()
{
    pArr arr = (pArr)malloc(sizeof(Array));
    arr->len = 0;
    arr->data = NULL;
    return arr;
}
void setLenArr(int len, pArr p_arr)
{
    p_arr->data = (int *)malloc(sizeof(int) * len);
    p_arr->len = len;
}
void printArr(Array arr)
{
    for (int i = 0; i < arr.len; i++)
    {
        printf("a[%d] = %d\n", i, arr.data[i]);
    }
}
void delArr(pArr p_arr)
{
    if (p_arr->data != NULL){
        free(p_arr->data);
    }
    free(p_arr);
}