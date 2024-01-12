#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer[3]={0,1,1};
    
    for(int i=3;i<=n;++i)
        answer[i%3]=(answer[(i+1)%3]+answer[(i+2)%3])%1234567;

    return answer[n%3];
}