#include<stdio.h>
#include<stdlib.h>

// survey_len은 배열 survey의 길이입니다.
// choices_len은 배열 choices의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* survey[], size_t survey_len, int choices[], size_t choices_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int RT=0, CF=0, JM=0, AN=0;
    
    char *answer=calloc(5,sizeof(char));
    
    for(int i=0;i<survey_len;i++)
        switch(survey[i][0])
        {
            case 'R':
                RT+=(choices[i]-4);
                break;
            case 'T':
                RT-=(choices[i]-4);
                break;
            case 'F':
                CF-=(choices[i]-4);
                break;
            case 'C':
                CF+=(choices[i]-4);
                break;
            case 'M':
                JM-=(choices[i]-4);
                break;
            case 'J':
                JM+=(choices[i]-4);
                break;
            case 'A':
                AN+=(choices[i]-4);
                break;
            case 'N':
                AN-=(choices[i]-4);
                break;
        }
    
    answer[0]=RT>0?'T':'R';
    answer[1]=CF>0?'F':'C';
    answer[2]=JM>0?'M':'J';
    answer[3]=AN>0?'N':'A';
    
    return answer;
}