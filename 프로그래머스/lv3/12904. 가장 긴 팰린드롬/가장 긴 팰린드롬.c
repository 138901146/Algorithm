#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include<string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    int answer = 1, length=strlen(s);
    
    for(int i=0;i<length;++i)
    {
        int count=1, left=i-1, right=i+1;
        
        while(left>=0 && right<length && s[left]==s[right])
        {
            count+=2;
            --left;
            ++right;
        }
        answer=count>answer?count:answer;
        
        count=0;
        left=i;
        right=i+1;
        
        while(left>=0 && right<length && s[left]==s[right])
        {
            count+=2;
            --left;
            ++right;
        }
        answer=count>answer?count:answer;
    }

    return answer;
}