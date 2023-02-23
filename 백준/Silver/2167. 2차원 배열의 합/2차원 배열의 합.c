#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, M, **arr=NULL, K;

	scanf("%d %d", &N, &M);
	arr=(int **)malloc(N*sizeof(int *));
	for(int n=0;n<N;n++)
		arr[n]=(int *)malloc(M*sizeof(int));

	for(int n=0;n<N;n++)
		for(int m=0;m<M;m++)
			scanf("%d", &arr[n][m]);

	scanf("%d", &K);

	for(int k=0;k<K;k++)
	{
		int i, j, x, y, sum=0;

		scanf("%d %d %d %d", &i, &j, &x, &y);

		for(int n=i-1;n<x;n++)
			for(int m=j-1;m<y;m++)
			sum+=arr[n][m];

		printf("%d\n", sum);
	}

	for(int n=0;n<N;n++)
		free(arr[n]);
	free(arr);
	return 0;
}