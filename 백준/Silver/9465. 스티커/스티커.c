#include<stdio.h>
#include<stdlib.h>

int max(int x,int y,int z)
{
	return x>=y&&x>=z?x:y>=x&&y>=z?y:z;
}

int main(void)
{
	int T;

	scanf("%d", &T);

	for(int t=0;t<T;t++)
	{
		int n, **score=NULL, **total=NULL, maxscore=0;

		scanf("%d", &n);
		score=(int **)malloc(2*sizeof(int *));
		for(int i=0;i<2;i++)
			score[i]=(int *)malloc(n*sizeof(int));
		total=(int **)malloc(2*sizeof(int *));
		for(int i=0;i<2;i++)
			total[i]=calloc(n,sizeof(int));

		for(int i=0;i<2;i++)
			for(int j=0;j<n;j++)
				scanf("%d", &score[i][j]);

		for(int j=0;j<n;j++)
			for(int i=0;i<2;i++)
			{
				if(j==0)
					total[i][j]=score[i][j];
				else if(j==1)
					total[i][j]=score[i][j]+total[(i+1)%2][j-1];
				else
					total[i][j]=score[i][j]+max(total[(i+1)%2][j-1],total[0][j-2],total[1][j-2]);

				maxscore=total[i][j]>maxscore?total[i][j]:maxscore;
			}

		printf("%d\n", maxscore);
		for(int i=0;i<2;i++)
			free(total[i]);
		free(total);
		for(int i=0;i<2;i++)
			free(score[i]);
		free(score);
	}

	return 0;
}