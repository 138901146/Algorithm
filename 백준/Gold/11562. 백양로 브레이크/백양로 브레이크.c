#include<stdio.h>

int main(void)
{
	int n, m, b, k, s, e, road[251][251];

	scanf("%d%d", &n, &m);

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			road[i][j]=100000;
		road[i][i]=0;
	}

	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d", &s, &e, &b);

		road[s][e]=0;
		road[e][s]=b?0:1;
	}

	for(int mid=1;mid<=n;mid++)
		for(int start=1;start<=n;start++)
			for(int end=1;end<=n;end++)
				road[start][end]=road[start][mid]+road[mid][end]<road[start][end]?road[start][mid]+road[mid][end]:road[start][end];

	scanf("%d", &k);
	for(int i=0;i<k;i++)
	{
		scanf("%d%d", &s, &e);
		printf("%d\n", road[s][e]);
	}

	return 0;
}