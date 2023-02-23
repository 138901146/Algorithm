#include<stdio.h>

int main(void)
{
	long long int n, fibonacci[91]={0,1,1};

	scanf("%lld", &n);

	for(int i=3;i<=n;i++)
		fibonacci[i]=fibonacci[i-1]+fibonacci[i-2];

	printf("%lld\n", fibonacci[n]);

	return 0;
}