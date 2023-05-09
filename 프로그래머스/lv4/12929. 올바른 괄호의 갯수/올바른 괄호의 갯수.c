#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int recursion(int open,int close)
{
    if(open>close)
        return 0;
    else if(open==0)
        return 1;
    return recursion(open-1,close)+recursion(open,close-1);
}

int solution(int n) {
    return recursion(n,n);
}