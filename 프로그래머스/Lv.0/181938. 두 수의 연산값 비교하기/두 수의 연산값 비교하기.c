#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int a, int b) {
    int temp=b, cat=a;
    
    while(temp)
    {
        cat*=10;
        temp/=10;
    }
    cat+=b;
    
    temp=a*b<<1;
    
    return cat<temp?temp:cat;
}