#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// users_rows는 2차원 배열 users의 행 길이, users_cols는 2차원 배열 users의 열 길이입니다.
// emoticons_len은 배열 emoticons의 길이입니다.
int* solution(int** users, size_t users_rows, size_t users_cols, int emoticons[], size_t emoticons_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)calloc(2,sizeof(int));
    int *sale_percent=(int *)malloc(emoticons_len*sizeof(int));

    for(int flag=0;flag<1<<2*emoticons_len;flag++)
    {
        int temp=flag, plus_count=0, sales_sum=0;
        for(int i=0;i<emoticons_len;i++)
        {
            sale_percent[i]=10*((temp&3)+1);
            temp>>=2;
        }
        for(int i=0;i<users_rows;i++)
        {
            int sum=0;
            for(int j=0;j<emoticons_len;j++)
                if(sale_percent[j]>=users[i][0])
                    sum+=(emoticons[j]/100)*(100-sale_percent[j]);
            if(sum>=users[i][1])
                plus_count++;
            else
                sales_sum+=sum;
        }
        
        if(plus_count>answer[0])
        {
            answer[0]=plus_count;
            answer[1]=sales_sum;
        }
        else if(plus_count==answer[0] && sales_sum>answer[1])
            answer[1]=sales_sum;
    }
    
    free(sale_percent);
    return answer;
}