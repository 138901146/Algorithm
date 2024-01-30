#include<stdio.h>

int T[501][501];

int main(void)
{
	int N, M, A, B, C;

	scanf("%d%d", &N, &M);

	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)
			scanf("%d", &T[i][j]);

	for(int mid=1;mid<=N;++mid)
		for(int start=1;start<=N;++start)
			for(int end=1;end<=N;++end)
				if(T[start][mid]+T[mid][end]<T[start][end])
					T[start][end]=T[start][mid]+T[mid][end];

	while(M--)
	{
		scanf("%d%d%d", &A, &B, &C);
		printf("%s\n", T[A][B]<=C?"Enjoy other party":"Stay here");
	}

	return 0;
}