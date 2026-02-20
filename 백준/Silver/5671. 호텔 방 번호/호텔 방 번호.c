#include<stdio.h>

int main(void)
{
	int count[5001]={0}, N, M;

	for(int i=1;i<5001;++i)
	{
		int current=i, digit[10]={0}, duplicate=0;

		while(current)
		{
			if(digit[current%10])
			{
				duplicate=1;
				break;
			}

			++digit[current%10];
			current/=10;
		}

		count[i]=count[i-1]+!duplicate;
	}

	while(scanf("%d%d", &N, &M)!=EOF)
		printf("%d\n", count[M]-count[N-1]);

	return 0;
}