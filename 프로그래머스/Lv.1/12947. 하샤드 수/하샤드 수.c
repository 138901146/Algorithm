#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool solution(int x) {
    int temp=x, sum=0;
    
    while(temp)
    {
        sum+=temp%10;
        temp/=10;
    }
    
    return !(x%sum);
}