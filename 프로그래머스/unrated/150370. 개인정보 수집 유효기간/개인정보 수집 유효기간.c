#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include<string.h>

// terms_len은 배열 terms의 길이입니다.
// privacies_len은 배열 privacies의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* today, const char* terms[], size_t terms_len, const char* privacies[], size_t privacies_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int today_year=2000+10*(today[2]-'0')+today[3]-'0', today_month=10*(today[5]-'0')+today[6]-'0', today_date=10*(today[8]-'0')+today[9]-'0';
    int months[26]={0, };
    for(int i=0;i<terms_len;i++)
        for(int j=2;j<strlen(terms[i]);j++)
        {
            months[terms[i][0]-'A']*=10;
            months[terms[i][0]-'A']+=terms[i][j]-'0';
        }
    int return_size=0, *answer=(int *)malloc(privacies_len*sizeof(int));
    for(int i=0;i<privacies_len;i++)
    {
        int year=2000+10*(privacies[i][2]-'0')+privacies[i][3]-'0', month=10*(privacies[i][5]-'0')+privacies[i][6]-'0', date=10*(privacies[i][8]-'0')+privacies[i][9]-'0', term=privacies[i][11]-'A';
        bool append=false;
        
        date--;
        if(date<1)
        {
            date=28;
            month--;
        }
        month+=months[term];
        while(month>12)
        {
            month-=12;
            year++;
        }
        
        if(year<today_year)
            append=true;
        else if(year==today_year)
        {
            if(month<today_month)
                append=true;
            else if(month==today_month)
                if(date<today_date)
                    append=true;
        }
        
        if(append)
            answer[return_size++]=i+1;
    }
    
    int* return_value = (int*)malloc(return_size*sizeof(int));
    for(int i=0;i<return_size;i++)
        return_value[i]=answer[i];
    free(answer);
    return return_value;
}