#include<stdio.h>

int main(void)
{
	int T;
	long long A, B;

	scanf("%d", &T);

	while(T--)
	{
		scanf("%lld%lld", &A, &B);
		printf("%lld\n", (A/B)*(A/B));
	}

	return 0;
}