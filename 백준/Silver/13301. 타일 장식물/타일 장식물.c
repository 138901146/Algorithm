#include<stdio.h>

int main(void)
{
	long long fibonacci[2]={6,4};
	int N;

	scanf("%d", &N);

	for(int n=3;n<=N;++n)
		fibonacci[n&1]+=fibonacci[(n&1)^1];

	printf("%lld", fibonacci[N&1]);
}