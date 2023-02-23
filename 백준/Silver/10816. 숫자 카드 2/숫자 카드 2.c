#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, M, *num=calloc(20000001,sizeof(int)), card;

	scanf("%d", &N);
	for(int n=0;n<N;n++)
	{
		scanf("%d", &card);
		num[card+10000000]++;
	}

	scanf("%d", &M);
	for(int m=0;m<M;m++)
	{
		scanf("%d", &card);
		printf("%d ", num[card+10000000]);
	}

	printf("\n");
	free(num);
	return 0;
}