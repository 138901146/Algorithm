#include<stdio.h>

int min[100001]={0, 1, 1, 2, 2, 1, 2};

int main(void)
{
	int N, coin[4]={1,2,5,7};

	scanf("%d", &N);

	for(int n=7;n<=N;++n)
	{
		min[n]=n;
		for(int i=0;i<4;++i)
			min[n]=min[n]<min[n-coin[i]]+1?min[n]:min[n-coin[i]]+1;
	}

	printf("%d", min[N]);
	return 0;
}