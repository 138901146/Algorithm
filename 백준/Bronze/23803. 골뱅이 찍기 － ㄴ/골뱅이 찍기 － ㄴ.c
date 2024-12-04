#include<stdio.h>

int main(void)
{
	int N;

	scanf("%d", &N);

	for(int i=0;i<4;++i)
		for(int j=0;j<N;++j)
		{
			for(int k=0;k<N;++k)
				printf("@");
			printf("\n");
		}
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<N;++j)
			printf("@@@@@");
		printf("\n");
	}

	return 0;
}