#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int count[2001]={1,1};
    
    for(int i=2;i<=n;++i)
        count[i]=(count[i-1]+count[i-2])%1234567;

    return count[n];
}