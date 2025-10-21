#include<stdio.h>

int main(void)
{
	int N, K, apple;

	scanf("%d%d", &N, &K);

	while(K--)
	{
		scanf("%d", &apple);
		printf("%d ", N-apple<apple-1?N:1);
	}

	return 0;
}