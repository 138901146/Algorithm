#include<stdio.h>

int main(void)
{
	long long S, N=1;

	scanf("%lld", &S);

	while(N++)
		if(N*(N+1)/2>S)
			break;

	printf("%lld\n", N-1);
	return 0;
}