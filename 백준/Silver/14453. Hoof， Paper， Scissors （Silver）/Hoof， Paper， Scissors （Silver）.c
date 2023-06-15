#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, **prefix=NULL, **suffix=NULL, *HPS=NULL, cases[9]={0, }, best=0;
	char FJ;

	scanf("%d", &N);
	HPS=(int *)malloc(N*sizeof(int));
	prefix=(int **)malloc((N+2)*sizeof(int *));
	suffix=(int **)malloc((N+2)*sizeof(int *));
	for(int n=0;n<N+2;n++)
	{
		prefix[n]=(int *)calloc(3,sizeof(int));
		suffix[n]=(int *)calloc(3,sizeof(int));
	}

	for(int n=0;n<N;n++)
	{
		getchar();
		scanf("%c", &FJ);
		HPS[n]=FJ=='H'?0:FJ=='S'?1:2;
	}

	for(int i=1;i<=N;i++)
	{
		for(int j=0;j<3;j++)
			prefix[i][j]=prefix[i-1][j];

		prefix[i][HPS[i-1]]++;
	}
	for(int i=N;i>0;i--)
	{
		for(int j=0;j<3;j++)
			suffix[i][j]=suffix[i+1][j];

		suffix[i][HPS[i-1]]++;
	}

	for(int n=1;n<=N;n++)
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				cases[3*i+j]=prefix[n][i]+suffix[n+1][j]>cases[3*i+j]?prefix[n][i]+suffix[n+1][j]:cases[3*i+j];

	for(int i=0;i<9;i++)
		best=cases[i]>best?cases[i]:best;

	printf("%d\n", best);
	for(int n=0;n<N+2;n++)
	{
		free(prefix[n]);
		free(suffix[n]);
	}
	free(prefix);
	free(suffix);
	free(HPS);
	return 0;
}