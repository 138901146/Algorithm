#include<stdio.h>

int main(void)
{
	int V, E, a, b, c, distance[401][401], max=200000000;

	scanf("%d%d", &V, &E);
	for(int i=1;i<=V;++i)
	{
		for(int j=1;j<=V;++j)
			distance[i][j]=100000000;
		distance[i][i]=0;
	}

	while(E--)
	{
		scanf("%d%d%d", &a, &b, &c);
		distance[a][b]=c;
	}

	for(int mid=1;mid<=V;++mid)
		for(int start=1;start<=V;++start)
			for(int end=1;end<=V;++end)
				if(distance[start][end]>distance[start][mid]+distance[mid][end])
					distance[start][end]=distance[start][mid]+distance[mid][end];

	for(int i=1;i<=V;++i)
		for(int j=i+1;j<=V;++j)
			if(distance[i][j]+distance[j][i]<max)
				max=distance[i][j]+distance[j][i];

	printf("%d", max>=100000000?-1:max);
	return 0;
}