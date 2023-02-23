#include<stdio.h>

int main(void)
{
	int N, M, count=1;

	scanf("%d%d", &N, &M);

	for(int n=0;n<N;n++)
	{
		for(int m=0;m<M;m++)
		{
			printf("%d", count++);
			if(m<M-1)
				printf(" ");
		}
		printf("\n");
	}

	return 0;
}