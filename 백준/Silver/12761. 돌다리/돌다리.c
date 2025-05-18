#include<stdio.h>
#include<malloc.h>
#include<memory.h>

int min[100001], queue[100001];

int main(void)
{
	int A, B, N, M, front=0, rear=1;

	scanf("%d%d%d%d", &A, &B, &N, &M);

	memset(min,-1,100001*sizeof(int));

	min[N]=0;
	queue[0]=N;

	while(front<rear && min[M]==-1)
	{
		long long cur=queue[front++], table[8]={cur-1,cur+1,cur-A,cur+A,cur-B,cur+B,cur*A,cur*B};

		for(int i=0;i<8;++i)
			if(0<table[i] && table[i]<100001 && min[table[i]]==-1)
			{
				min[table[i]]=min[cur]+1;
				queue[rear++]=table[i];
			}
	}

	printf("%d", min[M]);
	return 0;
}