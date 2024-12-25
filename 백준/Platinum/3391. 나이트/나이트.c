#include<stdio.h>
#include<stdbool.h>
#include<memory.h>

#define INF 99999

int adjacent_list[20001][8], adjacent_list_count[20001]={0}, level[20001], odd[20001]={0}, even[20001]={0};
//bool used[20001]={0};

bool dfs(int current)
{
	for(int i=0;i<adjacent_list_count[current];++i)
	{
		int next=adjacent_list[current][i];

		if(!even[next] || level[even[next]]==level[current]+1&&dfs(even[next]))
		{
			odd[current]=next;
			even[next]=current;
			return true;
		}
	}

	level[current]=INF;
	return false;
}

int main(void)
{
	int N, M, id[201][201]={0}, odd_count=1, even_count=1, dr[8]={-2,-1,1,2,2,1,-1,-2}, dc[8]={1,2,2,1,-1,-2,-2,-1}, matched=0, x, y, flow, queue[20001], front, rear, min_level=0;

	scanf("%d%d", &N, &M);

	for(int m=0;m<M;++m)
	{
		scanf("%d%d", &x, &y);
		id[x][y]=-1;
	}

	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)
			if(!id[i][j])
				id[i][j]=(i&1)==(j&1)?even_count++:odd_count++;

	for(int i=1;i<=N;++i)
		for(int j=i&1?2:1;j<=N;j+=2)
			if(id[i][j]!=-1)
				for(int k=0;k<8;++k)
				{
					int r=i+dr[k], c=j+dc[k];

					if(r<1 || N<r || c<1 || N<c || id[r][c]==-1)
						continue;

					adjacent_list[id[i][j]][adjacent_list_count[id[i][j]]++]=id[r][c];
				}

	do
	{
		flow=front=rear=0;
		min_level=INF;

		for(int i=1;i<odd_count;++i)
			if(!odd[i])
			{
				level[i]=0;
				queue[rear++]=i;
			}
			else
				level[i]=INF;

		while(front<rear)
		{
			int current=queue[front++];

			for(int i=0;i<adjacent_list_count[current];++i)
			{
				int next=adjacent_list[current][i];

				if(!even[next])
					min_level=level[current]+1;
				else if(level[even[next]]==INF)
				{
					level[even[next]]=level[current]+1;
					queue[rear++]=even[next];
				}
			}
		}

		for(int i=1;i<odd_count;++i)
			flow+=!odd[i]&&dfs(i);

		matched+=flow;
	}
	while(min_level!=INF);

	printf("%d", N*N-M-matched);
	return 0;
}