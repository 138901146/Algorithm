#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

typedef struct
{
	double x, y;
}
location;

int **reach=NULL, *reach_count=NULL, *status=NULL;
bool *visited=NULL;

bool dfs(int current)
{
	for(int i=0;i<reach_count[current];++i)
		if(!visited[reach[current][i]])
		{
			visited[reach[current][i]]=true;

			if(status[reach[current][i]]==0 || dfs(status[reach[current][i]]))
			{
				status[reach[current][i]]=current;
				return true;
			}
		}

	return false;
}

int main(void)
{
	int n, m;
	double s, v;

	while(scanf("%d%d%lf%lf", &n, &m, &s, &v)!=EOF)
	{
		int safe=0;
		location *gopher_location=malloc((n+1)*sizeof(location)), *hole_location=malloc(m*sizeof(location));
		reach_count=(int *)calloc(n+1,sizeof(reach_count));
		reach=(int **)malloc((n+1)*sizeof(int *));

		for(int i=1;i<=n;++i)
			scanf("%lf%lf", &gopher_location[i].x, &gopher_location[i].y);

		for(int i=0;i<m;++i)
		{
			scanf("%lf%lf", &hole_location[i].x, &hole_location[i].y);

			for(int j=1;j<=n;++j)
				if((hole_location[i].x-gopher_location[j].x)*(hole_location[i].x-gopher_location[j].x)+(hole_location[i].y-gopher_location[j].y)*(hole_location[i].y-gopher_location[j].y)<=v*v*s*s)
					++reach_count[j];
		}

		for(int i=1;i<=n;++i)
		{
			reach[i]=(int *)malloc(reach_count[i]*sizeof(int));
			reach_count[i]=0;
		}

		for(int i=0;i<m;++i)
			for(int j=1;j<=n;++j)
				if((hole_location[i].x-gopher_location[j].x)*(hole_location[i].x-gopher_location[j].x)+(hole_location[i].y-gopher_location[j].y)*(hole_location[i].y-gopher_location[j].y)<=v*v*s*s)
					reach[j][reach_count[j]++]=i;

		free(gopher_location);
		free(hole_location);
		visited=(bool *)malloc(m*sizeof(bool));
		status=(int *)calloc(m,sizeof(int));

		for(int i=1;i<=n;++i)
		{
			for(int j=0;j<m;++j)
				visited[j]=false;
			dfs(i);
		}

		for(int i=0;i<m;++i)
			safe+=status[i]>0;

		printf("%d\n", n-safe);
		for(int i=1;i<=n;++i)
			free(reach[i]);
		free(reach);
		free(reach_count);
		free(status);
		free(visited);
	}

	return 0;
}