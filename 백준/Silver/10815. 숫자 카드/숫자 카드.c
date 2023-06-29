#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, M, *card=(int *)calloc(666667,sizeof(int)), num;

	scanf("%d", &N);
	for(int n=0;n<N;n++)
	{
		scanf("%d", &num);
		num+=10000000;
		card[num/30]|=(1<<(num%30));
	}

	scanf("%d", &M);
	for(int m=0;m<M;m++)
	{
		scanf("%d", &num);
		num+=10000000;
		printf("%d ", (card[num/30]&(1<<(num%30)))?1:0);
	}

	free(card);
	return 0;
}