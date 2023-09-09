#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
int *solution(int numbers[],size_t numbers_len)
{
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int *answer=NULL, count=0;
    bool exist[201]={false, };
    
    for(int i=0;i<numbers_len-1;i++)
        for(int j=i+1;j<numbers_len;j++)
            exist[numbers[i]+numbers[j]]=true;
    
    for(int i=0;i<201;i++)
        count+=exist[i];
    
    answer=(int *)malloc(count*sizeof(int));
    
    for(int i=200;i>=0;i--)
        if(exist[i])
            answer[--count]=i;

    return answer;
}