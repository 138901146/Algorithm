#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
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
	short N, M, row[51][51]={0}, col[51][51]={0}, row_count=1, col_count=1, current=0, previous=1, count=0;
	char board[2][52]={0};

	scanf("%hd%hd", &N, &M);

	for(short n=1;n<=N;++n, current^=1, previous^=1)
	{
		memset(board[current],0,52*sizeof(char));
		getchar();
		scanf("%s", board[current]+1);

		for(short m=1;m<=M;++m)
			if(board[current][m]=='*')
			{
				col[n][m]=board[current][m-1]=='*'?col[n][m-1]:col_count++;
				row[n][m]=board[previous][m]=='*'?row[n-1][m]:row_count++;
			}
	}

	adjacent_list=(short **)malloc(row_count*sizeof(short *));
	adjacent_list_count=(short *)calloc(row_count,sizeof(short));

	for(short n=1;n<=N;++n)
		for(short m=1;m<=M;++m)
			if(row[n][m])
				++adjacent_list_count[row[n][m]];

	for(short i=1;i<row_count;++i)
	{
		adjacent_list[i]=(short *)malloc(adjacent_list_count[i]*sizeof(short));
		adjacent_list_count[i]=0;
	}

	for(short n=1;n<=N;++n)
		for(short m=1;m<=M;++m)
			if(row[n][m])
				adjacent_list[row[n][m]][adjacent_list_count[row[n][m]]++]=col[n][m];

	occupied=(short *)calloc(col_count,sizeof(short));
	visited=(bool *)malloc(col_count*sizeof(bool));
	for(short i=1;i<row_count;++i)
	{
		memset(visited,0,col_count);
		count+=dfs(i);
	}

	printf("%hd", count);
	for(short i=1;i<row_count;++i)
		free(adjacent_list[i]);
	free(adjacent_list);
	free(adjacent_list_count);
	free(occupied);
	free(visited);
	return 0;
}