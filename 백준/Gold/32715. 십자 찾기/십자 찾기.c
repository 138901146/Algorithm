#include<stdio.h>
#include<stdint.h>
#include<malloc.h>

int main(void)
{
	int N, M, K, **paper=NULL, **up=NULL, **down=NULL, **right=NULL, **left=NULL, count=0;

	scanf("%d%d", &N, &M);
	scanf("%d", &K);
	paper=(int **)malloc((N+2)*sizeof(int *));
	up=(int **)malloc((N+2)*sizeof(int *));
	down=(int **)malloc((N+2)*sizeof(int *));
	left=(int **)malloc((N+2)*sizeof(int *));
	right=(int **)malloc((N+2)*sizeof(int *));

	paper[0]=(int *)calloc(M+2,sizeof(int));
	up[0]=(int *)calloc(M+2,sizeof(int));
	down[0]=(int *)calloc(M+2,sizeof(int));
	left[0]=(int *)calloc(M+2,sizeof(int));
	right[0]=(int *)calloc(M+2,sizeof(int));

	for(int r=1;r<=N;++r)
	{
		paper[r]=(int *)calloc(M+2,sizeof(int));
		up[r]=(int *)calloc(M+2,sizeof(int));
		down[r]=(int *)calloc(M+2,sizeof(int));
		left[r]=(int *)calloc(M+2,sizeof(int));
		right[r]=(int *)calloc(M+2,sizeof(int));

		for(int c=1;c<=M;++c)
		{
			scanf("%d", &paper[r][c]);

			left[r][c]=paper[r][c]?left[r][c-1]+1:0;
			up[r][c]=paper[r][c]?up[r-1][c]+1:0;
		}
	}

	paper[N+1]=(int *)calloc(M+2,sizeof(int));
	up[N+1]=(int *)calloc(M+2,sizeof(int));
	down[N+1]=(int *)calloc(M+2,sizeof(int));
	left[N+1]=(int *)calloc(M+2,sizeof(int));
	right[N+1]=(int *)calloc(M+2,sizeof(int));

	for(int r=N;r;--r)
		for(int c=M;c;--c)
		{
			down[r][c]=paper[r][c]?down[r+1][c]+1:0;
			right[r][c]=paper[r][c]?right[r][c+1]+1:0;

			count+=K<up[r][c]&&K<down[r][c]&&K<left[r][c]&&K<right[r][c];
		}

	printf("%d", count);
	for(int r=0;r<N+2;++r)
	{
		free(paper[r]);
		free(up[r]);
		free(down[r]);
		free(left[r]);
		free(right[r]);
	}
	free(paper);
	free(up);
	free(down);
	free(left);
	free(right);
	return 0;
}