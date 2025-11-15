#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, ***arr=NULL, Q, x1, y1, x2, y2, num;

	scanf("%d", &N);
	arr=(int ***)malloc((N+1)*sizeof(int **));
	for(int i=0;i<=N;++i)
	{
		arr[i]=(int **)malloc((N+1)*sizeof(int *));
		for(int j=0;j<=N;++j)
			arr[i][j]=(int *)calloc(11,sizeof(int));
	}

	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)
		{
			scanf("%d", &num);
			for(int k=1;k<11;++k)
				arr[i][j][k]=arr[i-1][j][k]+arr[i][j-1][k]-arr[i-1][j-1][k];
			arr[i][j][num]++;
		}

	scanf("%d", &Q);
	while(Q--)
	{
		num=0;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		for(int i=1;i<11;++i)
			num+=arr[x2][y2][i]-arr[x2][y1-1][i]-arr[x1-1][y2][i]+arr[x1-1][y1-1][i]>0;
		printf("%d\n", num);
	}

	for(int i=0;i<=N;++i)
	{
		for(int j=0;j<=N;++j)
			free(arr[i][j]);
		free(arr[i]);
	}
	free(arr);
	return 0;
}