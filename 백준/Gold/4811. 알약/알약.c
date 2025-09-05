#include<stdio.h>

int main(void)
{
	long long N, count[31][31]={0};

	for(int i=1;i<31;++i)
	{
		count[i][0]=1;
		for(int j=1;j<=i;++j)
			count[i][j]+=count[i-1][j]+count[i][j-1];
	}

	scanf("%d", &N);
	while(N)
	{
		printf("%lld\n", count[N][N]);
		scanf("%d", &N);
	}

	return 0;
}