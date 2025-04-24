#include<stdio.h>

int main(void)
{
	int N, M;
	long long A=0;

	scanf("%d", &N);

	for(int i=0;i<N;++i)
	{
		scanf("%d", &M);
		A+=M;
	}

	printf("%lld", A-((long long)N*(N-1)>>1));
	return 0;
}