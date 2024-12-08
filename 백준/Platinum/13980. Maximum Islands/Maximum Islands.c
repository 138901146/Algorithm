#include<stdio.h>
#include<stdbool.h>
#include<memory.h>

int adjacent_list[1601][4], adjacent_list_count[1601]={0}, occupied[1601]={0};
bool visited[1601];

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

int main(vocloud_id)
{
	int n, m, dr[4]={-1,0,0,1}, dc[4]={0,-1,1,0}, land_id[40][40]={0}, land_id_count=0, queue[1600], cloud_id[40][40]={0}, cloud_id_count=0, matched=0;
	char grid[40][41]={0};

	scanf("%d%d", &n, &m);

	for(int i=0;i<n;++i)
		scanf("%s", grid[i]);

	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			if(grid[i][j]=='L' && !land_id[i][j])
			{
				int front=0, rear=1;

				land_id[i][j]=++land_id_count;
				queue[0]=i<<6|j;

				while(front<rear)
				{
					int queue_r=queue[front]>>6, queue_c=queue[front]&63;

					for(int k=0;k<4;++k)
					{
						int r=queue_r+dr[k], c=queue_c+dc[k];

						if(r<0 || n<=r || c<0 || m<=c || grid[r][c]!='L' || land_id[r][c])
							continue;

						land_id[r][c]=land_id_count;
						queue[rear++]=r<<6|c;
					}

					++front;
				}
			}
			else if(grid[i][j]=='C')
			{
				for(int k=0;k<4;++k)
				{
					int r=i+dr[k], c=j+dc[k];

					if(r<0 || n<=r || c<0 || m<=c)
						continue;
					else if(grid[r][c]=='L')
					{
						cloud_id[i][j]=-1;
						break;
					}
				}

				if(!cloud_id[i][j])
					cloud_id[i][j]=++cloud_id_count;
			}

	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			if(0<cloud_id[i][j])
			{
				for(int k=0;k<4;++k)
				{
					int r=i+dr[k], c=j+dc[k];

					if(r<0 || n<=r || c<0 || m<=c)
						continue;
					else if(0<cloud_id[r][c])
						adjacent_list[cloud_id[i][j]][adjacent_list_count[cloud_id[i][j]]++]=cloud_id[r][c];
				}
			}

	for(int i=1;i<=cloud_id_count;++i)
	{
		memset(visited,0,1601);
		matched+=dfs(i);
	}

	printf("%d", land_id_count+cloud_id_count-matched/2);
	return 0;
}