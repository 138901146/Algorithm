#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num)
{
    long long x = num;

    for(int count = 0; count <= 500; ++count)
        if(x == 1)
            return count;
        else if(x & 1)
            x = x * 3 + 1;
        else
            x >>= 1;

    return -1;
}