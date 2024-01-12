#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string, const char* letter) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int count=0, length=strlen(my_string);
    
    for(int i=0;i<length;++i)
        count+=my_string[i]==*letter;

    char* answer = (char*)calloc(length-count+1,sizeof(char));
    count=0;
    
    for(int i=0;i<length;++i)
        if(my_string[i]==*letter)
            ++count;
        else
            answer[i-count]=my_string[i];
    
    return answer;
}