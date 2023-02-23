#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, M, i, j, *arr=NULL, *accumulate=NULL;

	scanf("%d%d", &N, &M);
	arr=(int *)malloc(N*sizeof(int));
	accumulate=(int *)calloc(N,sizeof(int));

	for(int n=0;n<N;n++)
	{
		scanf("%d", &arr[n]);
		accumulate[n]=arr[n];
	}
	for(int n=1;n<N;n++)
		accumulate[n]+=accumulate[n-1];

	for(int m=0;m<M;m++)
	{
		scanf("%d%d", &i, &j);
		printf("%d\n", accumulate[j-1]-accumulate[i-1]+arr[i-1]);
	}

	free(arr);
	return 0;
}