#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

// paths_rows는 2차원 배열 paths의 행 길이, paths_cols는 2차원 배열 paths의 열 길이입니다.
// gates_len은 배열 gates의 길이입니다.
// summits_len은 배열 summits의 길이입니다.

int size=1;
long long *pq=NULL;

int max(int x,int y)
{
    return x>y?x:y;
}

void add(long long value)
{
    int index=size;
    pq[size++]=value;
    
    while(index>1)
    {
        int next=index>>1;
        
        if((pq[index]&16777215)<(pq[next]&16777215))
        {
            long long temp=pq[index];
            pq[index]=pq[next];
            pq[next]=temp;
            index=next;
        }
        else
            break;
    }
}

long long get()
{
    long long value=pq[1];
    pq[1]=pq[--size];
    int index=1;
    
    while(index<size)
    {
        int left=index<<1, right=left|1, next=right<size?(pq[left]&16777215)<(pq[right]&16777215)?left:right:right==size?left:index;
        
        if(index==next)
            break;
        else if((pq[index]&16777215)>(pq[next]&16777215))
        {
            long long temp=pq[index];
            pq[index]=pq[next];
            pq[next]=temp;
            index=next;
        }
        else
            break;
    }
    
    return value;
}

int *solution(int n, int** paths, size_t paths_rows, size_t paths_cols, int gates[], size_t gates_len, int summits[], size_t summits_len)
{
    int *answer=(int *)malloc(2*sizeof(int)), *route_count=(int *)calloc(n+1,sizeof(int)), ***route=(int ***)malloc((n+1)*sizeof(int **)), *intensity=(int *)malloc((n+1)*sizeof(int));
    bool *is_gate=(bool *)calloc(n+1,sizeof(bool)), *is_summit=(bool *)calloc(n+1,sizeof(bool));
    
    answer[0]=answer[1]=16777215;
    for(int i=0;i<gates_len;i++)
        is_gate[gates[i]]=true;
    for(int i=0;i<summits_len;i++)
        is_summit[summits[i]]=true;
    
    for(int i=0;i<paths_rows;i++)
    {
        if((!is_summit[paths[i][0]]) && (!is_gate[paths[i][1]]))
            route_count[paths[i][0]]++;
        if((!is_summit[paths[i][1]]) && (!is_gate[paths[i][0]]))
            route_count[paths[i][1]]++;
    }
    
    for(int i=1;i<=n;i++)
    {
        route[i]=(int **)malloc(route_count[i]*sizeof(int *));
        for(int j=0;j<route_count[i];j++)
            route[i][j]=(int *)malloc(2*sizeof(int));
        route_count[i]=0;
        intensity[i]=is_gate[i]?0:16777215;
    }
    
    for(int i=0;i<paths_rows;i++)
    {
        if((!is_summit[paths[i][0]]) && (!is_gate[paths[i][1]]))
        {
            route[paths[i][0]][route_count[paths[i][0]]][0]=paths[i][1];
            route[paths[i][0]][route_count[paths[i][0]]++][1]=paths[i][2];
        }
        if((!is_summit[paths[i][1]]) && (!is_gate[paths[i][0]]))
        {
            route[paths[i][1]][route_count[paths[i][1]]][0]=paths[i][0];
            route[paths[i][1]][route_count[paths[i][1]]++][1]=paths[i][2];
        }
    }

    pq=(long long *)malloc(100*n*sizeof(long long));
    for(int i=0;i<gates_len;i++)
        pq[size++]=(long long)gates[i]<<24;
    
    while(size>1)
    {
        long long next=get();
        int value=next&16777215, index=next>>24;
        
        if(intensity[index]==value)
            for(int i=0;i<route_count[index];i++)
            {
                int cost=max(intensity[index],route[index][i][1]), compare=route[index][i][0];
                
                if(intensity[compare]>cost)
                {
                    intensity[compare]=cost;
                    add((long long)compare<<24|cost);
                }
            }
    }
    
    for(int i=0;i<summits_len;i++)
        if(intensity[summits[i]]<answer[1] || (intensity[summits[i]]==answer[1] && summits[i]<answer[0]))
        {
            answer[0]=summits[i];
            answer[1]=intensity[summits[i]];
        }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<route_count[i];j++)
            free(route[i][j]);
        free(route[i]);
    }
    free(intensity);
    free(route);
    free(is_gate);
    free(is_summit);
    free(pq);
    free(route_count);
    
    return answer;
}