#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int compare(const void *x,const void *y)
{
    return *(int *)x<*(int *)y?1:-1;
}

// array_len은 배열 array의 길이입니다.
int solution(int array[], size_t array_len) {
    qsort((void *)array,array_len,sizeof(int),compare);
    return array[array_len>>1];
}