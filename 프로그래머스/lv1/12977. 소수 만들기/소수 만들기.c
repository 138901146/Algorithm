#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isPrime(int N)
{
    if(N==2)
        return true;
    else if(N%2==0)
        return false;
    for(int i=3;i*i<=N;i+=2)
        if(N%i==0)
            return false;
    return true;
}

// nums_len은 배열 nums의 길이입니다.
int solution(int nums[],size_t nums_len)
{
    int count=0;
    
    for(int i=0;i<nums_len-2;i++)
        for(int j=i+1;j<nums_len-1;j++)
            for(int k=j+1;k<nums_len;k++)
                count+=isPrime(nums[i]+nums[j]+nums[k]);
    
    return count;
}