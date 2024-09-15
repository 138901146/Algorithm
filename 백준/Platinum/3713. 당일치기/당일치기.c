#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int adjacent_list[501][499], adjacent_list_count[501], occupied[500];
bool visited[500];

int abs(int x)
{
	return x<0?-x:x;
}

bool dfs(int current)
{
	for(int i=0;i<adjacent_list_count[current];++i)
	{
		int next=adjacent_list[current][i];

		if(!visited[next])
		{
			visited[next]=true;

			if(!occupied[next] || dfs(occupied[next]))
			{
				occupied[next]=current;
				return true;
			}
		}
	}

	return false;
}

int main(void)
{
	int T;

	scanf("%d", &T);

	while(T--)
	{
		int N, M_count=1, F_count=0, height[500], matched=0, M[501], F[500];
		char gender, music[500][101]={0}, sport[500][101]={0};

		scanf("%d", &N);

		memset(adjacent_list,0,249999*sizeof(int));
		memset(adjacent_list_count,0,501*sizeof(int));
		memset(occupied,0,500*sizeof(int));

		for(int n=0;n<N;++n)
		{
			scanf("%d %c%s%s", &height[n], &gender, music[n], sport[n]);

			if(gender=='M')
				M[M_count++]=n;
			else
				F[F_count++]=n;
		}

		for(int m=1;m<M_count;++m)
			for(int f=0;f<F_count;++f)
				if(abs(height[M[m]]-height[F[f]])<=40 && !strcmp(music[M[m]],music[F[f]]) && strcmp(sport[M[m]],sport[F[f]]))
					adjacent_list[m][adjacent_list_count[m]++]=f;

		for(int m=1;m<M_count;++m)
		{
			memset(visited,0,F_count);
			matched+=dfs(m);
		}

		printf("%d\n", N-matched);
	}

	return 0;
}