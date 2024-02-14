#include<stdio.h>
#include<malloc.h>

#define INF 2000000

int main(void)
{
	int N, K, *doll=NULL, min=INF, rear=1;

	scanf("%d%d", &N, &K);
	doll=(int *)malloc((N+1)*sizeof(int));
	doll[0]=0;

	for(int n=1;n<=N;++n)
	{
		scanf("%d", &doll[n]);
		doll[n]=doll[n-1]+(doll[n]==1);
	}

	for(int front=0;front<=N && rear<=N;++front)
	{
		while(rear<=N && doll[rear]-doll[front]<K)
			++rear;

		if(K<=doll[rear]-doll[front])
			min=rear-front<min?rear-front:min;
	}

	printf("%d", min==INF?-1:min);
	free(doll);
	return 0;
}