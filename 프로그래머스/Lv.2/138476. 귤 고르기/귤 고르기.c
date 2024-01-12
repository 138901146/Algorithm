#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int compare(const void *x,const void *y)
{
    return *(int *)x<*(int *)y?1:-1;
}

int total[10000001]={0};

// tangerine_len은 배열 tangerine의 길이입니다.
int solution(int k, int tangerine[], size_t tangerine_len) {
    int answer=0, sum=0;
    
    for(int i=0;i<tangerine_len;++i)
        ++total[tangerine[i]];
    qsort((void *)total,(size_t)10000001,sizeof(int),compare);
    
    while(sum<k)
        sum+=total[answer++];

    return answer;
}