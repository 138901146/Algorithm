#include<stdio.h>

#define INF 999

int main(void)
{
	int N, K, A, B, friend[101][101];

	scanf("%d%d", &N, &K);

	for(int i=1;i<=N;++i)
	{
		for(int j=1;j<i;++j)
			friend[i][j]=friend[j][i]=INF;
		friend[i][i]=0;
	}

	while(K--)
	{
		scanf("%d%d", &A, &B);
		friend[A][B]=friend[B][A]=1;
	}

	for(int mid=1;mid<=N;++mid)
		for(int start=1;start<=N;++start)
			for(int end=1;end<=N;++end)
				friend[start][end]=friend[start][mid]+friend[mid][end]<friend[start][end]?friend[start][mid]+friend[mid][end]:friend[start][end];

	for(int i=1;i<=N;++i)
		for(int j=1;j<N;++j)
			if(6<friend[i][j])
			{
				printf("Big World!");
				return 0;
			}
	printf("Small World!");
	return 0;
}