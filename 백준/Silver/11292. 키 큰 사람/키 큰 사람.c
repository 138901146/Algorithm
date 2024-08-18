#include<stdio.h>

int main(void)
{
	int N;

	scanf("%d", &N);

	while(N)
	{
		char name[50][11]={0};
		float tall[50], tallest=0;

		for(int i=0;i<N;++i)
		{
			scanf("%s%f", name[i], &tall[i]);
			tallest=tall[i]<tallest?tallest:tall[i];
		}

		for(int i=0;i<N;++i)
			if(tall[i]==tallest)
				printf("%s ", name[i]);
		printf("\n");

		scanf("%d", &N);
	}

	return 0;
}