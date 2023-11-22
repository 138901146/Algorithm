#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

typedef struct
{
	double x, y;
}
location;

int **hide=NULL, *hide_count=NULL, *status=NULL;
bool *visited=NULL;

bool dfs(int current)
{
	for(int i=0;i<hide_count[current];++i)
		if(!visited[hide[current][i]])
		{
			visited[hide[current][i]]=true;

			if(status[hide[current][i]]==0 || dfs(status[hide[current][i]]))
			{
				status[hide[current][i]]=current;
				return true;
			}
		}

	return false;
}

int main(void)
{
	int N, M, safe=0;
	double S, V;
	location *mouse_location=NULL, *tunnel_location=NULL;

	scanf("%d%d%lf%lf", &N, &M, &S, &V);
	mouse_location=(location *)malloc((N+1)*sizeof(location));
	tunnel_location=(location *)malloc(M*sizeof(location));
	hide_count=(int *)calloc(N+1,sizeof(hide_count));
	hide=(int **)malloc((N+1)*sizeof(int *));

	for(int n=1;n<=N;++n)
		scanf("%lf%lf", &mouse_location[n].x, &mouse_location[n].y);

	for(int m=0;m<M;++m)
	{
		scanf("%lf%lf", &tunnel_location[m].x, &tunnel_location[m].y);

		for(int n=1;n<=N;++n)
			if((tunnel_location[m].x-mouse_location[n].x)*(tunnel_location[m].x-mouse_location[n].x)+(tunnel_location[m].y-mouse_location[n].y)*(tunnel_location[m].y-mouse_location[n].y)<=V*V*S*S)
				++hide_count[n];
	}

	for(int n=1;n<=N;++n)
	{
		hide[n]=(int *)malloc(hide_count[n]*sizeof(int));
		hide_count[n]=0;
	}

	for(int m=0;m<M;++m)
		for(int n=1;n<=N;++n)
			if((tunnel_location[m].x-mouse_location[n].x)*(tunnel_location[m].x-mouse_location[n].x)+(tunnel_location[m].y-mouse_location[n].y)*(tunnel_location[m].y-mouse_location[n].y)<=V*V*S*S)
				hide[n][hide_count[n]++]=m;

	free(mouse_location);
	free(tunnel_location);
	visited=(bool *)malloc(M*sizeof(bool));
	status=(int *)calloc(M,sizeof(int));

	for(int n=1;n<=N;++n)
	{
		for(int m=0;m<M;++m)
			visited[m]=false;
		dfs(n);
	}

	for(int m=0;m<M;++m)
		safe+=status[m]>0;

	printf("%d", N-safe);
	for(int n=1;n<=N;++n)
		free(hide[n]);
	free(hide);
	free(hide_count);
	free(status);
	free(visited);
	return 0;
}