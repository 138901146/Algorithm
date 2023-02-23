#include<stdio.h>

long long int koongFibonacci[68]={0, };

long long int koong(int N)
{
	if(koongFibonacci[N]!=0)
		return koongFibonacci[N];
	koongFibonacci[N]=koong(N-1)+koong(N-2)+koong(N-3)+koong(N-4);
	return koongFibonacci[N];
}

int main(void)
{
	int t, n;

	koongFibonacci[0]=koongFibonacci[1]=1;
	koongFibonacci[2]=2;
	koongFibonacci[3]=4;

	scanf("%d", &t);
	for(int i=0;i<t;i++)
	{
		scanf("%d", &n);
		printf("%lld\n", koong(n));
	}

	return 0;
}