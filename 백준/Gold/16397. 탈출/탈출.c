#include<stdio.h>
#include<memory.h>

int queue[100000], count[100000];

int main(void)
{
	int N, T, G, front=0, rear=1, proceeded=0;

	scanf("%d%d%d", &N, &T, &G);

	memset(count,-1,100000*sizeof(int));
	count[N]=0;
	queue[0]=N;

	while(count[G]==-1 && front<rear && proceeded<=T)
	{
		N=queue[front];

		proceeded=count[N]<proceeded?proceeded:count[N];

		if(N<99999 && count[N+1]==-1)
		{
			count[N+1]=count[N]+1;
			queue[rear++]=N+1;
		}

		N<<=1;

		if(99999<N)
		{
			++front;
			continue;
		}

		int temp=1;

		while(temp<=N)
			temp*=10;

		N-=temp/10;

		if(count[N]==-1)
		{
			count[N]=count[queue[front]]+1;
			queue[rear++]=N;
		}

		++front;
	}

	if(0<=count[G] && count[G]<=T)
		printf("%d", count[G]);
	else
		printf("ANG");
	return 0;
}