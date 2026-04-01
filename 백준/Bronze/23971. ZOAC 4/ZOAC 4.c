#include<stdio.h>

int main(void)
{
	int H, W, N, M;

	scanf("%d%d%d%d", &H, &W, &N, &M);

	H=H/(N+1)+(H%(N+1)!=0);
	W=W/(M+1)+(W%(M+1)!=0);

	printf("%d", H*W);
	return 0;
}