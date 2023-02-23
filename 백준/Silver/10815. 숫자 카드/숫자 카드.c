#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(void)
{
	int N, M, number;
	bool *plus=NULL, *minus=NULL;

	plus=(bool *)calloc(10000001,sizeof(bool));
	minus=(bool *)calloc(10000000,sizeof(bool));
	scanf("%d", &N);

	for(int n=0;n<N;n++)
	{
		scanf("%d", &number);

		if(number<0)
			minus[-number-1]=true;
		else
			plus[number]=true;
	}

	scanf("%d", &M);
	for(int m=0;m<M;m++)
	{
		scanf("%d", &number);
		printf("%d ", number<0?minus[-number-1]:plus[number]);
	}

	printf("\n");
	free(minus);
	free(plus);
	return 0;
}