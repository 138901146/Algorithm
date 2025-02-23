#include<stdio.h>

int abs(int x)
{
	return x<0?-x:x;
}

int main(void)
{
	int N, M, height[102][102]={0}, area=0;

	scanf("%d%d", &N, &M);

	for(int n=1;n<=N;++n)
		for(int m=1;m<=M;++m)
			scanf("%d", &height[n][m]);

	for(int n=1;n<N+2;++n)
		for(int m=1;m<M+2;++m)
		{
			area+=abs(height[n][m]-height[n][m-1]);
			area+=abs(height[n][m]-height[n-1][m]);
		}

	printf("%d", area+(N*M<<1));
	return 0;
}