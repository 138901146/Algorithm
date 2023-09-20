#include<stdio.h>

unsigned int n, m, D[1001][1001]={0, };

int main(void)
{
	scanf("%u%u", &n, &m);

	D[0][0]=1;

	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			D[i][j]=(D[i-1][j]+D[i][j-1]+D[i-1][j-1])%1000000007;

	printf("%u", D[n][m]);
	return 0;
}