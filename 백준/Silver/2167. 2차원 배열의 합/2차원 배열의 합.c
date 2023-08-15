#include<stdio.h>

int main(void)
{
	int N, M, arr[301][301]={0, }, K, i, j, x, y;

	scanf("%d%d", &N, &M);

	for(int n=1;n<=N;n++)
		for(int m=1;m<=M;m++)
		{
			scanf("%d", &arr[n][m]);
			arr[n][m]+=arr[n-1][m]+arr[n][m-1]-arr[n-1][m-1];
		}

	scanf("%d", &K);
	while(K--)
	{
		scanf("%d%d%d%d", &i, &j, &x, &y);
		printf("%d\n", arr[x][y]-arr[x][j-1]-arr[i-1][y]+arr[i-1][j-1]);
	}

	return 0;
}