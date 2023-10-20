#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// sequence_len은 배열 sequence의 길이입니다.
long long solution(int sequence[], size_t sequence_len) {
    long long max=sequence[0], sum=0;
    
    for(int i=0, flag=1;i<sequence_len;++i, flag=-flag)
    {
        sum=sum+flag*sequence[i]>flag*sequence[i]?sum+flag*sequence[i]:flag*sequence[i];
        max=max>sum?max:sum;
    }
    
    sum=0;
    for(int i=0, flag=-1;i<sequence_len;++i, flag=-flag)
    {
        sum=sum+flag*sequence[i]>flag*sequence[i]?sum+flag*sequence[i]:flag*sequence[i];
        max=max>sum?max:sum;
    }

    return max;
}