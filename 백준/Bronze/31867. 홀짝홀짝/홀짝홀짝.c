#include<stdio.h>

int main(void)
{
	int N, K, count[2]={0};

	scanf("%d", &N);

	while(N--)
	{
		scanf("%1d", &K);
		++count[K&1];
	}

	printf("%d", count[0]<count[1]?1:count[1]<count[0]?0:-1);
	return 0;
}