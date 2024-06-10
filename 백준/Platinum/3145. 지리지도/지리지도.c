#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<malloc.h>

bool *visited=NULL;
int n, **adjacent_list=NULL, *adjacent_list_size=NULL, *occupied=NULL;

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
	int R, C, village_size=0, capacity=1, id[51][51]={0}, location_size=1, location[2500];
	char **map=NULL, **village=malloc(sizeof(char *));

	scanf("%d%d", &R, &C);
	map=(char **)malloc((R+2)*sizeof(char *));
	adjacent_list=(int **)malloc(sizeof(int *));
	adjacent_list_size=(int *)calloc(1,sizeof(int));

	map[0]=(char *)calloc(C+2,sizeof(char));
	map[R+1]=(char *)calloc(C+2,sizeof(char));
	for(int r=1;r<=R;++r)
	{
		map[r]=(char *)calloc(C+2,sizeof(char));
		scanf("%s", map[r]+1);
	}

	for(int r=1;r<=R;++r)
		for(int c=1;c<=C;++c)
			if(map[r][c]!='.' && map[r][c]!='x')
			{
				int length=0;

				while(c+length<=C && map[r][c+length]!='.' && map[r][c+length]!='x')
					++length;

				if(village_size==capacity)
				{
					capacity<<=1;
					village=realloc(village,capacity*sizeof(char *));
					adjacent_list=realloc(adjacent_list,capacity*sizeof(int *));
					adjacent_list_size=realloc(adjacent_list_size,capacity*sizeof(int));
				}

				adjacent_list_size[village_size]=0;
				for(int i=c-1;i<=C && i<=c+length;++i)
				{
					if(map[r-1][i]=='x')
					{
						if(!id[r-1][i])
						{
							location[location_size]=(r-1)<<6|i;
							id[r-1][i]=location_size++;
						}

						++adjacent_list_size[village_size];
					}
					if(map[r+1][i]=='x')
					{
						if(!id[r+1][i])
						{
							location[location_size]=(r+1)<<6|i;
							id[r+1][i]=location_size++;
						}

						++adjacent_list_size[village_size];
					}
				}
				if(map[r][c-1]=='x')
				{
					if(!id[r][c-1])
					{
						location[location_size]=r<<6|c-1;
						id[r][c-1]=location_size++;
					}

					++adjacent_list_size[village_size];
				}
				if(map[r][c+length]=='x')
				{
					if(!id[r][c+length])
					{
						location[location_size]= r<<6|c+length;
						id[r][c+length]=location_size++;
					}

					++adjacent_list_size[village_size];
				}

				adjacent_list[village_size]=(int *)malloc(adjacent_list_size[village_size]*sizeof(int));
				adjacent_list_size[village_size]=0;

				for(int i=c-1;i<=C && i<=c+length;++i)
				{
					if(map[r-1][i]=='x')
						adjacent_list[village_size][adjacent_list_size[village_size]++]=id[r-1][i];
					if(map[r+1][i]=='x')
						adjacent_list[village_size][adjacent_list_size[village_size]++]=id[r+1][i];
				}
				if(map[r][c-1]=='x')
					adjacent_list[village_size][adjacent_list_size[village_size]++]=id[r][c-1];
				if(map[r][c+length]=='x')
					adjacent_list[village_size][adjacent_list_size[village_size]++]=id[r][c+length];

				village[village_size]=(char *)calloc(length+1,sizeof(char));
				strncpy(village[village_size++],map[r]+c,length);
				c+=length;
			}

	for(int r=0;r<R+2;++r)
		free(map[r]);
	free(map);

	occupied=(int *)calloc(location_size,sizeof(int));
	visited=(bool *)malloc(village_size*sizeof(int));

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

	for(int i=0;i<village_size;++i)
	{
		free(village[i]);
		free(adjacent_list[i]);
	}
	free(village);
	free(adjacent_list);
	free(adjacent_list_size);
	free(occupied);
	free(visited);
	return 0;
}