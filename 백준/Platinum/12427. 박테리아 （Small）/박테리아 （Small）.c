#include<stdio.h>
#include<stdbool.h>
#include<memory.h>

int adjacent_list[126][63], adjacent_list_count[126], occupied[126];
bool visited[126];

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

	for(int t=1;t<=T;++t)
	{
		int N, M, K, room=0, queue[25], dr[4]={-1,0,0,1}, dc[4]={0,-1,1,0}, dk[2]={-1,1}, id[5][5][5]={0}, matched=0;
		char B[5][5][5]={0};
		bool connected[125][125]={0};

		memset(adjacent_list_count,0,126*sizeof(int));
		memset(occupied,0,126*sizeof(int));

		scanf("%d%d%d", &N, &M, &K);

		for(int k=0;k<K;++k)
			for(int n=0;n<N;++n)
				scanf("%s", B[k][n]);

		for(int k=0;k<K;++k)
			for(int n=0;n<N;++n)
				for(int m=0;m<M;++m)
					if(B[k][n][m]=='.' && !id[k][n][m])
					{
						int front=0, rear=1;

						id[k][n][m]=++room;
						queue[0]=n<<3|m;

						while(front<rear)
						{
							for(int i=0;i<4;++i)
							{
								int r=(queue[front]>>3)+dr[i], c=(queue[front]&7)+dc[i];

								if(0<=r && r<N && 0<=c && c<M && B[k][r][c]=='.' && !id[k][r][c])
								{
									id[k][r][c]=room;
									queue[rear++]=r<<3|c;
								}
							}

							++front;
						}
					}

		for(int k=0;k<K;++k)
			for(int n=0;n<N;++n)
				for(int m=0;m<M;++m)
					if(id[k][n][m])
						for(int i=0;i<2;++i)
						{
							int next_k=k+dk[i];

							if(next_k<0 || K<=next_k || !id[next_k][n][m] || connected[id[k][n][m]][id[next_k][n][m]])
								continue;

							connected[id[k][n][m]][id[next_k][n][m]]=connected[id[k][n][m]][id[next_k][n][m]]=true;
							if(k&1)
								adjacent_list[id[k][n][m]][adjacent_list_count[id[k][n][m]]++]=id[next_k][n][m];
							else
								adjacent_list[id[next_k][n][m]][adjacent_list_count[id[next_k][n][m]]++]=id[k][n][m];
						}

		for(int i=1;i<=room;++i)
		{
			memset(visited,0,126);
			matched+=dfs(i);
		}

		printf("Case #%d: %d\n", t, room-matched);
	}

	return 0;
}