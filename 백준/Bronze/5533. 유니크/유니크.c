#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(void)
{
	int **score=NULL, N, *total=NULL;;

	scanf("%d", &N);
	total=(int *)calloc(N,sizeof(int));
	score=(int **)malloc(N*sizeof(int *));
	for(int i=0;i<N;i++)
		score[i]=(int *)malloc(3*sizeof(int));

	for(int i=0;i<N;i++)
		for(int j=0;j<3;j++)
			scanf("%d", &score[i][j]);

	for(int i=0;i<3;i++)
		for(int j=0;j<N;j++)
		{
			bool same=false;

			for(int k=0;k<N;k++)
				if(j==k)
					continue;
				else if(score[j][i]==score[k][i])
				{
					same=true;
					break;
				}

			if(!same)
				total[j]+=score[j][i];
		}

	for(int i=0;i<N;i++)
		printf("%d\n", total[i]);
	for(int i=0;i<N;i++)
		free(score[i]);
	free(score);
	free(total);
	return 0;
}