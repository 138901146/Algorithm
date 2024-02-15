#include<stdio.h>

int sum[1000001]={0};

int main(void)
{
	int N, K, g, x, end=0, right, left, max=0, range;

	scanf("%d%d", &N, &K);
	while(N--)
	{
		scanf("%d%d", &g, &x);
		sum[x]=g;
		end=x>end?x:end;
	}

	range=K<<1|1;
	for(int i=1;i<=end;++i)
	{
		sum[i]+=sum[i-1];

		if(i-range>=0)
			max=sum[i]-sum[i-range]>max?sum[i]-sum[i-range]:max;
		else
			max=sum[i]>max?sum[i]:max;
	}

	printf("%d", max);
	return 0;
}