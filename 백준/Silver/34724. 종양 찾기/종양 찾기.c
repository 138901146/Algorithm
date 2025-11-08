#include<stdio.h>

int xray[1000][1000];

int main(void)
{
	int N, M;

	scanf("%d%d", &N, &M);

	for(int n=0;n<N;++n)
		for(int m=0;m<M;++m)
			scanf("%1d", &xray[n][m]);

	for(int n=1;n<N;++n)
		for(int m=1;m<M;++m)
			if(xray[n-1][m-1]&&xray[n-1][m]&&xray[n][m-1]&&xray[n][m])
			{
				printf("1");
				return 0;
			}

	printf("0");
	return 0;
}