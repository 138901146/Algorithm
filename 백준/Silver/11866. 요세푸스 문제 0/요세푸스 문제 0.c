#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, K, front=0, rear, *Y=NULL;

	scanf("%d%d", &N, &K);
	Y=(int *)malloc(N*sizeof(int));

	for(rear=0;rear<N;rear++)
		Y[rear]=rear+1;

	printf("<");
	for(int n=0;n<N;n++)
	{
		for(int k=1;k<K;k++)
			Y[(rear++)%N]=Y[(front++)%N];
		printf("%d", Y[(front++)%N]);
		printf("%s", n==N-1?">":", ");
	}

	free(Y);
	return 0;
}