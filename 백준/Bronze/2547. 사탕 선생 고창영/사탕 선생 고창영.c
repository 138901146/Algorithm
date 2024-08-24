#include<stdio.h>

int main(void)
{
	int T;

	scanf("%d", &T);

	while(T--)
	{
		int N;
		unsigned long long candy, mod=0;

		scanf("%d", &N);

		for(int i=0;i<N;++i)
		{
			scanf("%llu", &candy);
			mod=(mod+candy)%N;
		}

		printf("%s\n", mod?"NO":"YES");
	}

	return 0;
}