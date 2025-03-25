#include<stdio.h>

int main(void)
{
	long long R, C, N;

	scanf("%lld%lld%lld", &R, &C, &N);

	if(R%N)
		R=R/N+1;
	else
		R=R/N;

	if(C%N)
		C=C/N+1;
	else
		C=C/N;

	printf("%lld", R*C);
	return 0;
}