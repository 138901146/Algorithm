#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(const char* my_string) {
    int length = strlen(my_string);
    char* answer = (char*)calloc(length+1,sizeof(char));
    
    for(int i=0;i<length;++i)
        answer[length-1-i] = my_string[i];
    
    return answer;
}