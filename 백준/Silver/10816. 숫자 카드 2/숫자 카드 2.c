#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, M, *card=(int *)calloc(20000001,sizeof(int)), num;

	scanf("%d", &N);
	for(int n=0;n<N;n++)
	{
		scanf("%d", &num);
		card[num+10000000]++;
	}

	scanf("%d", &M);
	for(int m=0;m<M;m++)
	{
		scanf("%d", &num);
		printf("%d ", card[num+10000000]);
	}

	free(card);
	return 0;
}