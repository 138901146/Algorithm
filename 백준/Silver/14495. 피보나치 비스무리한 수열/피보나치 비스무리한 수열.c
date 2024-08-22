#include<stdio.h>

int main(void)
{
	int n;
	long long fibonacci[4]={2,1,1,1};

	scanf("%d", &n);

	for(int i=5;i<=n;++i)
		fibonacci[i&3]=fibonacci[i-1&3]+fibonacci[i+1&3];

	printf("%lld", fibonacci[n&3]);
	return 0;
}