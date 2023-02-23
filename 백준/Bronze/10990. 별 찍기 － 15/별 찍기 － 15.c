#include<stdio.h>

int main(void)
{
	int N;

	scanf("%d", &N);

	for(int i=1;i<=N;i++)
	{
		for(int j=0;i+j<N;j++)
			printf(" ");
		printf("*");
		if(i>1)
		{
			printf(" ");
			for(int j=2;j<i;j++)
				printf("  ");
			printf("*");
		}
		printf("\n");
	}

	return 0;
}