#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int arr[], size_t arr_len) {
    for(int i=0;i<arr_len;++i)
        if(arr[i]>49 && !(arr[i]&1))
            arr[i]>>=1;
        else if(arr[i]<50 && (arr[i]&1))
            arr[i]<<=1;
    
    return arr;
}