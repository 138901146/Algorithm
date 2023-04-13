#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int N, M, **tetromino=NULL, move[4][2]={{-1,0},{0,-1},{0,1},{1,0}};
bool **visited=NULL;

int recursion(int count,int y,int x)
{
	int sum, max=0;

	if(count==3)
		return 0;
	else if(count==0)
	{
		if(y<N-1 && x>0 && x+1<M)
		{
			sum=tetromino[y+1][x-1]+tetromino[y+1][x]+tetromino[y+1][x+1];
			max=sum>max?sum:max;
		}
		if(y>0 && x>0 && x+1<M)
		{
			sum=tetromino[y-1][x-1]+tetromino[y-1][x]+tetromino[y-1][x+1];
			max=sum>max?sum:max;
		}
		if(x<M-1 && y>0 && y+1<N)
		{
			sum=tetromino[y-1][x+1]+tetromino[y][x+1]+tetromino[y+1][x+1];
			max=sum>max?sum:max;
		}
		if(x>0 && y>0 && y+1<N)
		{
			sum=tetromino[y-1][x-1]+tetromino[y][x-1]+tetromino[y+1][x-1];
			max=sum>max?sum:max;
		}
	}

	for(int i=0;i<4;i++)
		if(y+move[i][0]>=0 && y+move[i][0]<N && x+move[i][1]>=0 && x+move[i][1]<M && !visited[y+move[i][0]][x+move[i][1]])
		{
			visited[y+move[i][0]][x+move[i][1]]=true;
			sum=tetromino[y+move[i][0]][x+move[i][1]]+recursion(count+1,y+move[i][0],x+move[i][1]);
			max=sum>max?sum:max;
			visited[y+move[i][0]][x+move[i][1]]=false;
		}

	return max;
}

int main(void)
{
	int max=0, sum;

	scanf("%d%d", &N, &M);
	tetromino=(int **)malloc(N*sizeof(int *));
	visited=(bool **)malloc(N*sizeof(bool *));
	for(int i=0;i<N;i++)
	{
		tetromino[i]=(int *)malloc(M*sizeof(int));
		visited[i]=(bool *)calloc(M,sizeof(bool));
		for(int j=0;j<M;j++)
			scanf("%d", &tetromino[i][j]);
	}

	for(int n=0;n<N;n++)
		for(int m=0;m<M;m++)
		{
			visited[n][m]=true;
			sum=tetromino[n][m]+recursion(0,n,m);
			max=sum>max?sum:max;
			visited[n][m]=false;
		}

	printf("%d\n", max);
	for(int n=0;n<N;n++)
	{
		free(tetromino[n]);
		free(visited[n]);
	}
	free(tetromino);
	free(visited);
	return 0;
}