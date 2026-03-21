#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, a, b, **X=NULL;

	scanf("%d%d%d", &N, &a, &b);

	--a;
	--b;

	X=(int **)malloc(N*sizeof(int *));

	for(int i=0;i<N;++i)
	{
		X[i]=(int *)malloc(N*sizeof(int));
		for(int j=0;j<N;++j)
			scanf("%d", &X[i][j]);
	}

	for(int i=0;i<N;++i)
		if(X[a][b]<X[a][i]||X[a][b]<X[i][b])
		{
			printf("ANGRY");
			for(int j=0;j<N;++j)
				free(X[j]);
			free(X);
			return 0;
		}

	printf("HAPPY");
	for(int i=0;i<N;++i)
		free(X[i]);
	free(X);
	return 0;
}