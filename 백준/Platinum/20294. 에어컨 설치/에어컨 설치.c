#include<stdio.h>
#include<stdbool.h>
#include<memory.h>

int id[401][401][401]={0}, adjacent_list[1501][6], adjacent_list_count[1501]={0}, occupied[1501]={0};
bool visited[1501];

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
	int N, location[1501][3], x, y, z, dx[6]={-1,1,0,0,0,0}, dy[6]={0,0,-1,1,0,0}, dz[6]={0,0,0,0,-1,1}, matched=0;

	scanf("%d", &N);

	for(int n=1;n<=N;++n)
	{
		for(int i=0;i<3;++i)
		{
			scanf("%d", &location[n][i]);
			location[n][i]+=200;
		}

		id[location[n][0]][location[n][1]][location[n][2]]=n;
	}

	for(int n=1;n<=N;++n)
	{
		x=location[n][0];
		y=location[n][1];
		z=location[n][2];

		for(int i=0;i<6;++i)
		{
			int next_x=x+dx[i], next_y=y+dy[i], next_z=z+dz[i];

			if(next_x<0 || 400<next_x || next_y<0 || 400<next_y || next_z<0 || 400<next_z)
				continue;

			if(id[next_x][next_y][next_z])
				adjacent_list[n][adjacent_list_count[n]++]=id[next_x][next_y][next_z];
		}

		matched+=!adjacent_list_count[n];

		if(!(x+y+z&1))
			adjacent_list_count[n]=0;
	}

	for(int n=1;n<=N;++n)
	{
		memset(visited,0,1501);
		matched+=dfs(n);
	}

	printf("%d", matched);
	return 0;
}