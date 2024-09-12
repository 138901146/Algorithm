#include<stdio.h>

int main(void)
{
	int n, abs, fibonacci[3]={0,1,1};

	scanf("%d", &n);

	abs=n<0?-n:n;

	for(int i=3;i<=abs;++i)
		fibonacci[i%3]=(fibonacci[(i+1)%3]+fibonacci[(i+2)%3])%1000000000;

	printf("%d\n%d", 0<n?1:n==0?0:abs&1?1:-1, fibonacci[abs%3]);
	return 0;
}