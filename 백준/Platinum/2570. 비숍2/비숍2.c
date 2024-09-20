#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>
#include<memory.h>

short **adjacent_list=NULL, *adjacent_list_count=NULL, *occupied=NULL;
bool *visited=NULL;

bool dfs(short current)
{
	for(short i=0;i<adjacent_list_count[current];++i)
	{
		short next=adjacent_list[current][i];

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
	short N, M, one_three[101][101]={0}, two_four[101][101]={0}, r, c, one_three_count=1, two_four_count=1, bishop=0;
	bool blocked[101][101]={0};

	scanf("%hd", &N);
	scanf("%hd", &M);

	while(M--)
	{
		scanf("%hd%hd", &r, &c);
		blocked[r][c]=true;
	}

	for(r=1;r<=N;++r,++one_three_count)
		for(c=1;c<=r;++c)
			if(blocked[r-c+1][c])
			{
				while(c<=r && blocked[r-c+1][c])
					++c;
				if(c<=r && !blocked[r-c+1][c])
					--c;
				++one_three_count;
			}
			else
				one_three[r-c+1][c]=one_three_count;

	for(c=2;c<=N;++c,++one_three_count)
		for(r=N;c<=r;--r)
			if(blocked[r][N-r+c])
			{
				while(c<=r && blocked[r][N-r+c])
					--r;
				if(c<=r && !blocked[r][N-r+c])
					++r;
				++one_three_count;
			}
			else
				one_three[r][N-r+c]=one_three_count;

	adjacent_list_count=(short *)calloc(one_three_count,sizeof(short));
	adjacent_list=(short **)malloc(one_three_count*sizeof(short *));

	for(c=1;c<=N;++c,++two_four_count)
		for(r=1;r+c<=N+1;++r)
			if(blocked[r][r+c-1])
			{
				while(r+c<=N+1 && blocked[r][r+c-1])
					++r;
				if(r+c<=N+1 && !blocked[r][r+c-1])
					--r;
				++two_four_count;
			}
			else
			{
				++adjacent_list_count[one_three[r][r+c-1]];
				two_four[r][r+c-1]=two_four_count;
			}

	for(r=2;r<=N;++r,++two_four_count)
		for(c=1;r+c<=N+1;++c)
			if(blocked[r+c-1][c])
			{
				while(r+c<=N+1 && blocked[r+c-1][c])
					++c;
				if(r+c<=N+1 && !blocked[r+c-1][c])
						--c;
				++two_four_count;
			}
			else
			{
				++adjacent_list_count[one_three[r+c-1][c]];
				two_four[r+c-1][c]=two_four_count;
			}

	for(short i=1;i<one_three_count;++i)
	{
		adjacent_list[i]=(short *)malloc(adjacent_list_count[i]*sizeof(short));
		adjacent_list_count[i]=0;
	}

	for(r=1;r<=N;++r)
		for(c=1;c<=N;++c)
			if(!blocked[r][c])
				adjacent_list[one_three[r][c]][adjacent_list_count[one_three[r][c]]++]=two_four[r][c];

	visited=(bool *)malloc(two_four_count*sizeof(bool));
	occupied=(short *)calloc(two_four_count,sizeof(short));

	for(short i=1;i<one_three_count;++i)
	{
		memset(visited,0,two_four_count);
		bishop+=dfs(i);
	}

	printf("%hd", bishop);
	for(short i=1;i<one_three_count;++i)
		free(adjacent_list[i]);
	free(adjacent_list);
	free(adjacent_list_count);
	free(occupied);
	free(visited);
	return 0;
}