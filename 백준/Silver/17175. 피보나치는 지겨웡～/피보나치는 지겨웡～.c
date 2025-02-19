#include<stdio.h>

#define MOD 1000000007

int main(void)
{
	int n, fibonacci[3]={1,1};

	scanf("%d", &n);

	for(int i=2;i<=n;++i)
		fibonacci[i%3]=(fibonacci[(i+1)%3]+fibonacci[(i+2)%3]+1)%MOD;

	printf("%d", fibonacci[n%3]);
	return 0;
}