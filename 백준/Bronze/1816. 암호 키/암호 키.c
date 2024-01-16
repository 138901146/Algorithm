#include<stdio.h>

int is_prime(long long x)
{
	if(x<1000001)
		return 0;
	else if(!(x&1))
		return 0;
	for(long long i=3;i*i<=x && i<1000001;i+=2)
		if(!(x%i))
			return 0;
	return 1;
}

int main(void)
{
	int N;
	long long S;

	scanf("%d", &N);

	while(N--)
	{
		scanf("%lld", &S);
		printf("%s\n", is_prime(S)?"YES":"NO");
	}

	return 0;
}