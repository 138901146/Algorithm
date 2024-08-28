#include<stdio.h>
#include<stdbool.h>
#include<memory.h>

short piece[101][101], piece_count[101], occupied[101];
bool visited[101];

bool dfs(short current)
{
	for(short i=0;i<piece_count[current];++i)
	{
		short next=piece[current][i];

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
	short T, n, m, t1, t2, a, q;
	bool existence[101][101];

	scanf("%hd", &T);

	while(T--)
	{
		short received=0;

		memset(existence,0,10201);
		memset(piece_count,0,101*sizeof(short));

		scanf("%hd%hd", &n, &m);

		while(m--)
		{
			scanf("%hd%hd%hd", &t1, &t2, &a);

			while(a--)
			{
				scanf("%hd", &q);
				for(short i=t1+1;i<=t2;++i)
					existence[i][q]=true;
			}
		}

		for(short i=0;i<101;++i)
		{
			occupied[i]=-1;
			for(short j=0;j<101;++j)
				if(existence[i][j])
					piece[i][piece_count[i]++]=j;
		}

		for(short i=1;i<101;++i)
		{
			memset(visited,0,101);
			received+=dfs(i);

			if(received==n)
			{
				printf("%hd\n", i);
				break;
			}
		}

		if(received!=n)
			printf("-1\n");
	}

	return 0;
}