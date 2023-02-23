#include<stdio.h>

int main(void)
{
	int N;

	scanf("%d", &N);

	for(int i=0;i<N;i++)
	{
		for(int j=0;j<(N%2==0?N/2:N/2+1);j++)
			printf("* ");
		printf("\n");
		for(int j=0;j<N/2;j++)
			printf(" *");
		printf("\n");
	}

	return 0;
}