#include<stdio.h>

int main(void)
{
	int N, M, stone[2][301]={0}, current=0, previous=1;

	scanf("%d%d", &N, &M);

	for(int n=1;n<=N;++n, current^=1, previous^=1)
		for(int m=1;m<=M;++m)
		{
			scanf("%d", &stone[current][m]);
			stone[current][m]+=stone[previous][m]<stone[current][m-1]?stone[current][m-1]:stone[previous][m];
		}

	printf("%d", stone[previous][M]);
	return 0;
}