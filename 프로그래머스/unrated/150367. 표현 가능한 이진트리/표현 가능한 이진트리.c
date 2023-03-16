#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
int* solution(long long numbers[], size_t numbers_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(numbers_len*sizeof(int));
    int bit[64], left[64], right[64], level[64], queue[64];

    for(int i=1;i<64;i++)
    {
        int count=0, temp=i;
        while((temp&1)==0)
        {
            count++;
            temp>>=1;
        }
        level[i]=count;
    }
    
    for(int i=0;i<numbers_len;i++)
    {
        answer[i]=1;
        long long temp=numbers[i];
        int size=0, front=0, rear=0, count=0;
        while(temp>0)
        {
            size++;
            temp>>=1;
        }
//        size++;
        temp=0;
        while(size>=(1<<temp))
            temp++;
        size=(1<<temp)-1;
        temp=numbers[i];

        for(int j=size;j>0;j--,temp>>=1)
        {
            left[j]=right[j]=0;
            bit[j]=temp&1;
            count+=bit[j];
        }
        
        for(int j=2;j<=size;j++)
            left[j]=bit[j-1]==1?0:left[j-1]+1;
        for(int j=size-1;j>0;j--)
            right[j]=bit[j+1]==1?0:right[j+1]+1;

//        for(int j=1;j<=size;j++)
//            if(bit[j]==0 && (left[j]<level[j] || right[j]<level[j]))
//            {
//                answer[i]=0;
//                break;
//            }
        
        if(bit[(size+1)/2]==1)
            queue[rear++]=(size+1)/2;
        while(front<rear)
        {
            if(level[queue[front]]>0)
            {
                if(bit[queue[front]+(1<<(level[queue[front]]-1))]==1)
                    queue[rear++]=queue[front]+(1<<(level[queue[front]]-1));
                if(bit[queue[front]-(1<<(level[queue[front]])-1)]==1)
                    queue[rear++]=queue[front]-(1<<(level[queue[front]]-1));
            }
            front++;
        }
        if(count!=rear)
        {
            printf("%lld: %d %d ", numbers[i], count, rear);
            answer[i]=0;
        }
    }

    return answer;
}