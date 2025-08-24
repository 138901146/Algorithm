#include<stdio.h>

int main(void)
{
	int N, M;
	long long answer=1;

	scanf("%d", &N);
	scanf("%d", &M);

	for(int i=1;i<N;++i)
	{
		answer*=(long long)M-i;
		answer/=(long long)i;
	}

	printf("%lld", answer);
	return 0;
}