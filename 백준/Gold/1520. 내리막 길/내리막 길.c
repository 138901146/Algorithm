#include<stdio.h>
#include<stdlib.h>

int N, M, **map=NULL, **method=NULL;

int route(int y,int x)
{
	if(y==M-1 && x==N-1)
		return 1;
	else if(method[y][x]!=-1)
		return method[y][x];
	else
		method[y][x]=0;

	if(x>0 && map[y][x-1]<map[y][x])
		method[y][x]+=route(y,x-1);
	if(x<N-1 && map[y][x+1]<map[y][x])
		method[y][x]+=route(y,x+1);
	if(y>0 && map[y-1][x]<map[y][x])
		method[y][x]+=route(y-1,x);
	if(y<M-1 && map[y+1][x]<map[y][x])
		method[y][x]+=route(y+1,x);


	return method[y][x];
}

int main(void)
{
	scanf("%d%d", &M, &N);
	map=(int **)malloc(M*sizeof(int *));
	method=(int **)malloc(M*sizeof(int *));
	for(int m=0;m<M;m++)
	{
		map[m]=(int *)malloc(N*sizeof(int));
		method[m]=(int *)malloc(N*sizeof(int));

		for(int n=0;n<N;n++)
		{
			scanf("%d", &map[m][n]);
			method[m][n]=-1;
		}
	}

	printf("%d\n", route(0,0));
	for(int m=0;m<M;m++)
	{
		free(method[m]);
		free(map[m]);
	}
	free(method);
	free(map);
	return 0;
}