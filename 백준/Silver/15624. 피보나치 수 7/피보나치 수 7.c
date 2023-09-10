#include<stdio.h>

int main(void)
{
	int n, fibonacci[3]={0,1,1};

	scanf("%d", &n);

	for(int i=3;i<=n;++i)
		fibonacci[i%3]=(fibonacci[(i+1)%3]+fibonacci[(i+2)%3])%1000000007;

	printf("%d", fibonacci[n%3]);
	return 0;
}