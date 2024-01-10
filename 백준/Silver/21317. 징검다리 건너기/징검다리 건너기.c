#include<stdio.h>

int min2(int x,int y)
{
	return x<y?x:y;
}

int min3(int x,int y,int z)
{
	return x<=y&&x<=z?x:y<=x&&y<=z?y:z;
}

int main(void)
{
	int N, K, small[20], big[20], efficient[20][2]={0};

	scanf("%d", &N);
	for(int n=0;n<N-1;++n)
		scanf("%d%d", &small[n], &big[n]);
	scanf("%d", &K);

	efficient[1][0]=small[0];
	efficient[2][0]=big[0]<small[0]+small[1]?big[0]:small[0]+small[1];
	efficient[0][1]=efficient[1][1]=efficient[2][1]=1000000000;
	for(int n=3;n<N;++n)
	{
		efficient[n][0]=min2(efficient[n-1][0]+small[n-1],efficient[n-2][0]+big[n-2]);
		efficient[n][1]=min3(efficient[n-1][1]+small[n-1],efficient[n-2][1]+big[n-2],efficient[n-3][0]+K);
	}

	printf("%d", min2(efficient[N-1][0],efficient[N-1][1]));
	return 0;
}