#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int left,int right)
{
    int answer=0;

    for(int i=left;i<=right;i++)
    {
        int count=0;
        
        for(int j=1;j<=i;j++)
            count+=i%j==0;
        
        if(count%2==0)
            answer+=i;
        else
            answer-=i;
    }

    return answer;
}