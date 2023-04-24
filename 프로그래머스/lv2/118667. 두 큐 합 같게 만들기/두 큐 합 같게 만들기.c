#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// queue1_len은 배열 queue1의 길이입니다.
// queue2_len은 배열 queue2의 길이입니다.
int solution(int queue1[], size_t queue1_len, int queue2[], size_t queue2_len) {
    int answer = 0, q1_front=0, q2_front=0, q1_rear=queue1_len, q2_rear=queue2_len, size=2*queue1_len;
    int *q1=malloc(size*sizeof(int)), *q2=malloc(size*sizeof(int));
    long q1_sum=0, q2_sum=0;
    
    for(int i=0;i<queue1_len;i++)
    {
        q1[i]=queue1[i];
        q2[i]=queue2[i];
        q1_sum+=q1[i];
        q2_sum+=q2[i];
    }
    
    while(q1_sum!=q2_sum && q1_front<q1_rear && q2_front<q2_rear && answer<=2*size)
    {
        answer++;
        if(q1_sum<q2_sum)
        {
            q1[(q1_rear++)%size]=q2[(q2_front++)%size];
            q1_sum+=q1[(q1_rear-1)%size];
            q2_sum-=q2[(q2_front-1)%size];
        }
        else
        {
            q2[(q2_rear++)%size]=q1[(q1_front++)%size];
            q2_sum+=q2[(q2_rear-1)%size];
            q1_sum-=q1[(q1_front-1)%size];
        }
    }
    
    free(q1);
    free(q2);
    
    if(q1_sum!=q2_sum)
        return -1;
    
    return answer;
}