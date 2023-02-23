#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, **G=NULL;

	scanf("%d", &N);
	G=(int **)malloc(N*sizeof(int *));
	for(int n=0;n<N;n++)
		G[n]=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			scanf("%d", &G[i][j]);

	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			if(G[i][j])
				for(int k=0;k<N;k++)
					if(G[k][i])
						G[k][j]=1;
			if(G[j][i])
				for(int k=0;k<N;k++)
					if(G[k][j])
						G[k][i]=1;
		}

	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
			printf("%d ", G[i][j]);
		printf("\n");
		free(G[i]);
	}
	free(G);
	return 0;
}