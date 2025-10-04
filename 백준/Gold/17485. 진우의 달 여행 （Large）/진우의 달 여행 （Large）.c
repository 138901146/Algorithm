#include<stdio.h>
#include<malloc.h>

#define INF 999999999

int main(void)
{
	int N, M, **matrix=NULL, smallest[1000][3][2]={0,}, current=0, next=1, direction[3]={-1,0,1}, min=INF;

	scanf("%d%d", &N, &M);
	matrix=(int **)malloc(N*sizeof(int *));
	for(int n=0;n<N;++n)
	{
		matrix[n]=(int *)malloc(M*sizeof(int));
		for(int m=0;m<M;++m)
			scanf("%d", &matrix[n][m]);
	}

	for(int n=0;n<N;++n,current^=1,next^=1)
	{
		for(int m=0;m<M;++m)
			for(int i=0;i<3;++i)
				smallest[m][i][next]=INF;

		for(int m=0;m<M;++m)
			for(int i=0;i<3;++i)
				for(int j=0;j<3;++j)
					if(i!=j&&0<=m+direction[j]&&m+direction[j]<M)
						smallest[m+direction[j]][j][next]=smallest[m][i][current]+matrix[n][m]<smallest[m+direction[j]][j][next]?smallest[m][i][current]+matrix[n][m]:smallest[m+direction[j]][j][next];
	}

	for(int m=0;m<M;++m)
		for(int i=0;i<3;++i)
			min=smallest[m][i][current]<min?smallest[m][i][current]:min;
	printf("%d", min);
	while(N)
		free(matrix[--N]);
	free(matrix);
	return 0;
}