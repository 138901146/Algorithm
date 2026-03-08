#include<stdio.h>

#define INF 1234567

int main(void)
{
	int N, L[301], R[301], friendship[301][301], Q, A, B;

	scanf("%d", &N);

	for(int i=1;i<=N;++i)
		scanf("%d%d", &L[i], &R[i]);

	for(int i=1;i<=N;++i)
	{
		for(int j=1;j<i;++j)
			if(L[i]<L[j]&&R[i]<L[j]||L[j]<L[i]&&R[j]<L[i])
				friendship[i][j]=friendship[j][i]=INF;
			else
				friendship[i][j]=friendship[j][i]=1;
		friendship[i][i]=0;
	}

	for(int mid=1;mid<=N;++mid)
		for(int src=1;src<=N;++src)
			for(int dst=1;dst<=N;++dst)
				friendship[src][dst]=friendship[src][dst]<friendship[src][mid]+friendship[mid][dst]?friendship[src][dst]:friendship[src][mid]+friendship[mid][dst];

	scanf("%d", &Q);

	while(Q--)
	{
		scanf("%d%d", &A, &B);

		printf("%d\n", friendship[A][B]==INF?-1:friendship[A][B]);
	}

	return 0;
}