#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
int solution(int numbers[], size_t numbers_len) {
    int primary = 0, secondary=0;
    
    for(int i=0;i<numbers_len;++i)
        if(numbers[i]>primary)
        {
            secondary=primary;
            primary=numbers[i];
        }
        else if(numbers[i]>secondary)
            secondary=numbers[i];

    return primary*secondary;
}