#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool visited[300]={false};
int adjacent_list[300][106], adjacent_list_size[300]={0}, occupied[300];

bool dfs(int current)
{
	for(int i=0;i<adjacent_list_size[current];++i)
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
	int R, C, village_size=0, id[51][51]={0}, location_size=1, location[301];
	char map[52][52]={0}, village[300][51]={0};

	scanf("%d%d", &R, &C);
	for(int r=1;r<=R;++r)
		scanf("%s", map[r]+1);

	for(int r=1;r<=R;++r)
		for(int c=1;c<=C;++c)
			if(map[r][c]!='.' && map[r][c]!='x')
			{
				int length=0;

				while(c+length<=C && map[r][c+length]!='.' && map[r][c+length]!='x')
					++length;

				for(int i=c-1;i<=C && i<=c+length;++i)
				{
					if(map[r-1][i]=='x')
					{
						if(!id[r-1][i])
						{
							location[location_size]=(r-1)<<6|i;
							id[r-1][i]=location_size++;
						}

						adjacent_list[village_size][adjacent_list_size[village_size]++]=id[r-1][i];
					}
					if(map[r+1][i]=='x')
					{
						if(!id[r+1][i])
						{
							location[location_size]=(r+1)<<6|i;
							id[r+1][i]=location_size++;
						}

						adjacent_list[village_size][adjacent_list_size[village_size]++]=id[r+1][i];
					}
				}
				if(map[r][c-1]=='x')
				{
					if(!id[r][c-1])
					{
						location[location_size]=r<<6|c-1;
						id[r][c-1]=location_size++;
					}

					adjacent_list[village_size][adjacent_list_size[village_size]++]=id[r][c-1];
				}
				if(map[r][c+length]=='x')
				{
					if(!id[r][c+length])
					{
						location[location_size]= r<<6|c+length;
						id[r][c+length]=location_size++;
					}

					adjacent_list[village_size][adjacent_list_size[village_size]++]=id[r][c+length];
				}

				strncpy(village[village_size++],map[r]+c,length);
				c+=length;
			}

	for(int i=0;i<location_size;++i)
		occupied[i]=-1;

	for(int i=0;i<village_size;++i)
	{
		for(int j=0;j<location_size;++j)
			visited[j]=false;

		dfs(i);
	}

	for(int i=1;i<location_size;++i)
		printf("%d %d %s\n", location[i]>>6, location[i]&63, village[occupied[i]]);

	return 0;
}