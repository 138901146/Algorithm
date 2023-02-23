#include<stdio.h>

int main(void)
{
	int N, i, j;

	scanf("%d", &N);

	for(i=0;i<N;i++)
		printf("*");
	for(i=0;i<2*N-3;i++)
		printf(" ");
	for(i=0;i<N;i++)
		printf("*");
	printf("\n");

	for(i=2;i<N;i++)
	{
		for(j=1;j<i;j++)
			printf(" ");
		printf("*");
		for(j=1;j<N-1;j++)
			printf(" ");
		printf("*");
		for(j=0;j<2*(N-i)-1;j++)
			printf(" ");
		printf("*");
		for(j=1;j<N-1;j++)
			printf(" ");
		printf("*");
		printf("\n");
	}

	for(i=1;i<N;i++)
		printf(" ");
	printf("*");
	for(i=1;i<N-1;i++)
		printf(" ");
	printf("*");
	for(i=1;i<N-1;i++)
		printf(" ");
	printf("*");
	printf("\n");

	for(i=N-1;i>1;i--)
	{
		for(j=1;j<i;j++)
			printf(" ");
		printf("*");
		for(j=1;j<N-1;j++)
			printf(" ");
		printf("*");
		for(j=0;j<2*(N-i)-1;j++)
			printf(" ");
		printf("*");
		for(j=1;j<N-1;j++)
			printf(" ");
		printf("*");
		printf("\n");
	}

	for(i=0;i<N;i++)
		printf("*");
	for(i=0;i<2*N-3;i++)
		printf(" ");
	for(i=0;i<N;i++)
		printf("*");
	printf("\n");

	return 0;
}