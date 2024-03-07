#include<stdio.h>

int main(void)
{
	int tc=0, N, number;

	scanf("%d", &N);

	while(N)
	{
		++tc;
		while(N--)
			scanf("%d", &number);
		scanf("%d", &N);
	}

	for(int i=1;i<=tc;++i)
		printf("Case %d: Sorting... done!\n", i);
	return 0;
}