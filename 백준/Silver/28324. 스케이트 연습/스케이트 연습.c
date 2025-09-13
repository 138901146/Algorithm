#include<stdio.h>
#include<malloc.h>

int min(int x,int y,int z)
{
	return x<=y&&x<=z?x:y<=x&&y<=z?y:z;
}

int main(void)
{
	int N, *V=NULL, max[2]={0,1}, current=0, previous=1;
	long long result=1;

	scanf("%d", &N);
	V=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;++i)
		scanf("%d", &V[i]);

	for(int i=2;i<=N;++i)
	{
		max[current]=min(i,V[N-i],max[previous]+1);
		result+=max[current];
		current^=1;
		previous^=1;
	}

	printf("%lld", result);
	free(V);
	return 0;
}