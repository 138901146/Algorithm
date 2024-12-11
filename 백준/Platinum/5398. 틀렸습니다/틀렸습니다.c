#include<stdio.h>
#include<stdbool.h>
#include<memory.h>
#include<string.h>

int id[1001][1001], adjacent_list[500][500], adjacent_list_count[500], occupied[500];
bool visited[500];
char puzzle[1001][1002];

bool dfs(int current)
{
	for(int i=0;i<adjacent_list_count[current];++i)
	{
		int next=adjacent_list[current][i];

		if(!visited[next])
		{
			visited[next]=true;

			if(occupied[next]==-1 || dfs(occupied[next]))
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
	int T, H, V, x, y, matched;
	char W[1001]={0};

	scanf("%d", &T);

	while(T--)
	{
		memset(adjacent_list_count,0,500*sizeof(int));
		memset(occupied,-1,500*sizeof(int));
		memset(puzzle,0,1003002*sizeof(char));
		memset(id,-1,1002001*sizeof(int));
		matched=0;

		scanf("%d%d", &H, &V);

		for(int h=0;h<H;++h)
		{
			scanf("%d%d%s", &x, &y, W);

			for(int i=0;i<strlen(W);++i)
				if(x+i<1001)
				{
					puzzle[x+i][y]=W[i];
					id[x+i][y]=h;
				}
				else
					break;
		}

		for(int v=0;v<V;++v)
		{
			scanf("%d%d%s", &x, &y, W);

			for(int i=0;i<strlen(W);++i)
				if(y+i<1001)
				{
					if(id[x][y+i]!=-1 && puzzle[x][y+i]!=W[i])
						adjacent_list[v][adjacent_list_count[v]++]=id[x][y+i];
				}
				else
					break;
		}

		for(int v=0;v<V;++v)
		{
			memset(visited,0,500);
			matched+=dfs(v);
		}

		printf("%d\n", H+V-matched);
	}

	return 0;
}