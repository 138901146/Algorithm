#include<stdio.h>

int main(void)
{
	long long N, K;

	scanf("%lld%lld", &K, &N);

	if(N==1)
		printf("-1");
	else if(N*K%(N-1))
		printf("%lld", N*K/(N-1)+1);
	else
		printf("%lld", N*K/(N-1));
	return 0;
}