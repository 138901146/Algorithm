#include<stdio.h>

int main(void)
{
	int N, candy[999], first=0;

	scanf("%d", &N);

	for(int n=0;n<N;++n)
	{
		scanf("%d", &candy[n]);
		first+=n&1?-candy[n]:candy[n];
	}

	candy[0]-=first>>1;
	printf("%d", first>>1);
	for(int n=0;n<N-1;++n)
	{
		printf("\n%d", candy[n]);
		candy[n+1]-=candy[n];
	}

	return 0;
}