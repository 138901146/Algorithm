#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// a_len은 배열 a의 길이입니다.
int solution(int a[], size_t a_len) {
    int answer = 0, smallest=2000000000;
    bool bigger[1000000]={false};
    
    for(int i=0;i<a_len;++i)
        if(a[i]>smallest)
            bigger[i]=true;
        else
            smallest=a[i];
    
    smallest=2000000000;
    for(int i=a_len-1;i>=0;--i)
        if(a[i]<smallest)
        {
            ++answer;
            smallest=a[i];
        }
        else
            if(!bigger[i])
                ++answer;
    
    return answer;
}