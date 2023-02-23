#include<stdio.h>

int main(void)
{
	int N;

	scanf("%d", &N);

	for(int i=N;i>0;i--)
	{
		for(int j=0;i+j<N;j++)
			printf(" ");
		printf("*");
		for(int j=1;j<i;j++)
			printf("**");
		printf("\n");
	}
	for(int i=2;i<=N;i++)
	{
		for(int j=0;i+j<N;j++)
			printf(" ");
		printf("*");
		for(int j=1;j<i;j++)
			printf("**");
		printf("\n");
	}

	return 0;
}