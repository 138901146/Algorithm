#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, *T=NULL, *P=NULL, *max=NULL;

	scanf("%d", &N);
	T=(int *)malloc(N*sizeof(int));
	P=(int *)malloc(N*sizeof(int));
	max=(int *)calloc(N+1,sizeof(int));

	for(int i=0;i<N;i++)
	{
		scanf("%d%d", &T[i], &P[i]);
		if(T[i]+i<=N)
			max[T[i]+i]=max[i]+P[i]>max[T[i]+i]?max[i]+P[i]:max[T[i]+i];
		max[i+1]=max[i]>max[i+1]?max[i]:max[i+1];
	}

	printf("%d\n", max[N]);
	free(max);
	free(T);
	free(P);
	return 0;
}