#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

// edges_rows는 2차원 배열 edges의 행 길이, edges_cols는 2차원 배열 edges의 열 길이입니다.
// target_len은 배열 target의 길이입니다.
int* solution(int** edges, size_t edges_rows, size_t edges_cols, int target[], size_t target_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int *answer=NULL, *child_count=(int *)calloc(target_len+1,sizeof(int)), **child=(int **)malloc((target_len+1)*sizeof(int *)), *index=(int *)calloc(target_len+1,sizeof(int)), leaf_count=0, *frequency=(int *)calloc(target_len+1,sizeof(int)), *order=(int *)malloc(1000*sizeof(int)), order_count=0, satisfy=0;
    
    for(int i=0;i<edges_rows;i++)
        child_count[edges[i][0]]++;
    
    for(int i=1;i<=target_len;i++)
    {
        child[i]=(int *)malloc(child_count[i]*sizeof(int));
        leaf_count+=child_count[i]==0&&target[i-1]>0;
        child_count[i]=0;
    }
    
    for(int i=0;i<edges_rows;i++)
        child[edges[i][0]][child_count[edges[i][0]]++]=edges[i][1];
    
    for(int i=1;i<=target_len;i++)
        for(int j=0;j<child_count[i];j++)
            for(int k=j+1;k<child_count[i];k++)
                if(child[i][j]>child[i][k])
                {
                    int temp=child[i][j];
                    child[i][j]=child[i][k];
                    child[i][k]=temp;
                }
    while(satisfy<leaf_count)
    {
        int node=1;
        while(child_count[node]>0)
        {
            index[node]%=child_count[node];
            node=child[node][index[node]++];
        }
        order[order_count++]=node;
        frequency[node]++;
        if(frequency[node]>target[node-1])
        {
            for(int i=1;i<=target_len;i++)
                free(child[i]);
            free(child);
            free(child_count);
            free(index);
            free(frequency);
            free(order);
            answer=(int *)malloc(sizeof(int));
            answer[0]=-1;
            return answer;
        }
        else if(3*(frequency[node]-1)<target[node-1] && 3*frequency[node]>=target[node-1])
            satisfy++;
    }
    
    answer=(int *)malloc(order_count*sizeof(int));
    for(int i=order_count-1;i>=0;i--)
        if(target[order[i]-1]-3>=frequency[order[i]]-1)
        {
            answer[i]=3;
            target[order[i]-1]-=3;
            frequency[order[i]]--;
        }
        else if(target[order[i]-1]-2>=frequency[order[i]]-1)
        {
            answer[i]=2;
            target[order[i]-1]-=2;
            frequency[order[i]]--;
        }
        else
        {
            answer[i]=1;
            target[order[i]-1]--;
            frequency[order[i]]--;
        }
    
    for(int i=1;i<=target_len;i++)
        free(child[i]);
    free(child);
    free(child_count);
    free(index);
    free(frequency);
    free(order);
    return answer;
}