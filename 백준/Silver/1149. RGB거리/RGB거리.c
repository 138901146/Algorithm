#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, **cost=NULL;

	scanf("%d", &N);
	cost=(int **)malloc(N*sizeof(int *));
	for(int n=0;n<N;n++)
		cost[n]=(int *)malloc(3*sizeof(int));

	for(int n=0;n<N;n++)
		for(int i=0;i<3;i++)
			scanf("%d", &cost[n][i]);

	for(int n=1;n<N;n++)
	{
		cost[n][0]=cost[n-1][1]<cost[n-1][2]?cost[n-1][1]+cost[n][0]:cost[n-1][2]+cost[n][0];
		cost[n][1]=cost[n-1][0]<cost[n-1][2]?cost[n-1][0]+cost[n][1]:cost[n-1][2]+cost[n][1];
		cost[n][2]=cost[n-1][0]<cost[n-1][1]?cost[n-1][0]+cost[n][2]:cost[n-1][1]+cost[n][2];
	}

	printf("%d\n", cost[N-1][0]<=cost[N-1][1]&&cost[N-1][0]<=cost[N-1][2]?cost[N-1][0]:cost[N-1][1]<=cost[N-1][0]&&cost[N-1][1]<=cost[N-1][2]?cost[N-1][1]:cost[N-1][2]);
	for(int n=0;n<N;n++)
		free(cost[n]);
	free(cost);
	return 0;
}