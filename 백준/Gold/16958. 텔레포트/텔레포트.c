#include<stdio.h>

int abs(int x)
{
	return x<0?-x:x;
}

int N, T, x[1001], y[1001], distance[1001][1001], special[1000], special_count=0, s, M, A, B;

int main(void)
{
	scanf("%d%d", &N, &T);

	for(int i=1;i<=N;++i)
	{
		scanf("%d%d%d", &s, &x[i], &y[i]);

		if(s)
			special[special_count++]=i;

		for(int j=1;j<=i;++j)
			distance[i][j]=distance[j][i]=abs(x[i]-x[j])+abs(y[i]-y[j]);
	}

	for(int i=0;i<special_count;++i)
		for(int j=i+1;j<special_count;++j)
			if(T<distance[special[i]][special[j]])
				distance[special[i]][special[j]]=distance[special[j]][special[i]]=T;

	for(int mid=1;mid<=N;++mid)
		for(int start=1;start<=N;++start)
			for(int end=1;end<=N;++end)
				if(distance[start][mid]+distance[mid][end]<distance[start][end])
					distance[start][end]=distance[start][mid]+distance[mid][end];

	scanf("%d", &M);
	while(M--)
	{
		scanf("%d%d", &A, &B);
		printf("%d\n", distance[A][B]);
	}

	return 0;
}