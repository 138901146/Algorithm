#include<stdio.h>

int main(void)
{
	int N;
	long long max[101]={0};

	scanf("%d", &N);

	for(int n=0;n<=N;++n)
	{
		for(int i=n+1;i<=N;++i)
			max[i]=max[i-1]+1<max[i]?max[i]:max[i-1]+1;
		for(int i=n+3;i<=N;++i)
			max[i]=(i-n-1)*max[n]<max[i]?max[i]:(i-n-1)*max[n];
	}

	printf("%lld", max[N]);
	return 0;
}