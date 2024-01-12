#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
int solution(int numbers[], size_t numbers_len) {
    int count[10]={0}, sum=0;
    
    for(int i=0;i<numbers_len;++i)
        count[numbers[i]]=1;
    
    for(int i=0;i<10;++i)
        if(!count[i])
            sum+=i;
    
    return sum;
}