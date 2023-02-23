#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(void)
{
	int N, M, B, **land=NULL, min=256, max=0, best=2100000000, best_height;

	scanf("%d%d%d", &N, &M, &B);
	land=(int **)malloc(N*sizeof(int *));
	for(int n=0;n<N;n++)
		land[n]=(int *)malloc(M*sizeof(int));

	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
		{
			scanf("%d", &land[i][j]);
			if(land[i][j]>max)
				max=land[i][j];
			if(land[i][j]<min)
				min=land[i][j];
		}

	for(int count=min;count<=max;count++)
	{
		int sec=0, left=B;
		bool able=true;

		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
				if(land[i][j]>count)
				{
					sec+=2*(land[i][j]-count);
					left+=land[i][j]-count;
				}

		for(int i=0;i<N;i++)
		{
			for(int j=0;j<M;j++)				
				if(land[i][j]<count)
				{
					sec+=count-land[i][j];
					if(count-land[i][j]>left)
					{
						able=false;
						break;
					}
					left-=count-land[i][j];
				}
			if(!able)
				break;
		}

		if(able && sec<=best)
		{
			best=sec;
			best_height=count;
		}
	}

	printf("%d %d\n", best, best_height);
	for(int n=0;n<N;n++)
		free(land[n]);
	free(land);
	return 0;
}