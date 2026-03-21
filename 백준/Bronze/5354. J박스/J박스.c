#include<stdio.h>

int main(void)
{
	int T, N;

	scanf("%d", &T);

	while(T--)
	{
		scanf("%d", &N);

		if(N==1)
			printf("#\n");
		else
		{
			for(int i=0;i<N;++i)
				printf("#");
			printf("\n");
			for(int i=1;i<N-1;++i)
			{
				printf("#");
				for(int j=1;j<N-1;++j)
					printf("J");
				printf("#\n");
			}
			for(int i=0;i<N;++i)
				printf("#");
			printf("\n");
		}
		if(T)
			printf("\n");
	}

	return 0;
}