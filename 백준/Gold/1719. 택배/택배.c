#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int n, m, **delivery=NULL, list[3], **distance=NULL;

	scanf("%d%d", &n, &m);
	delivery=(int **)malloc((n+1)*sizeof(int *));
	distance=(int **)malloc((n+1)*sizeof(int *));
	for(int i=1;i<=n;i++)
	{
		delivery[i]=(int *)malloc((n+1)*sizeof(int));
		distance[i]=(int *)malloc((n+1)*sizeof(int));
		for(int j=1;j<=n;j++)
		{
			delivery[i][j]=j;
			distance[i][j]=1<<20;
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<3;j++)
			scanf("%d", &list[j]);
		if(distance[list[0]][list[1]]>list[2])
			distance[list[0]][list[1]]=list[2];
		if(distance[list[1]][list[0]]>list[2])
			distance[list[1]][list[0]]=list[2];
	}

	for(int t=1;t<=n;t++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				for(int k=1;k<=n;k++)
					if(distance[i][j]>distance[i][k]+distance[k][j])
					{
						distance[i][j]=distance[i][k]+distance[k][j];
						delivery[i][j]=delivery[i][k];
					}

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			if(i==j || distance[i][j]==1<<20)
				printf("- ");
			else
				printf("%d ", delivery[i][j]);
		printf("\n");
		free(distance[i]);
		free(delivery[i]);
	}
	free(distance);
	free(delivery);
	return 0;
}