#include<stdio.h>

long long g[1000001]={0};

int main(void)
{
	int T, N;

	for(int i=1;i<1000001;++i)
	{
		for(int j=i;j<1000001;j+=i)
			g[j]+=i;
		g[i]+=g[i-1];
	}

	scanf("%d", &T);

	while(T--)
	{
		scanf("%d", &N);
		printf("%lld\n", g[N]);
	}

	return 0;
}