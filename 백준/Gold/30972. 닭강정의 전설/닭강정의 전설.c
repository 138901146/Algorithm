#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, **k=NULL, Q, r1, c1, r2, c2;

	scanf("%d", &N);

	k=(int **)malloc((N+1)*sizeof(int *));
	for(int i=0;i<=N;++i)
		k[i]=(int *)calloc(N+1,sizeof(int));

	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)
		{
			scanf("%d", &k[i][j]);
			k[i][j]+=k[i-1][j]+k[i][j-1]-k[i-1][j-1];
		}

	scanf("%d", &Q);

	while(Q--)
	{
		scanf("%d%d%d%d", &r1, &c1, &r2, &c2);

		int data=k[r2-1][c2-1]-k[r1][c2-1]-k[r2-1][c1]+k[r1][c1];

		data-=k[r1][c2]-k[r1-1][c2]-k[r1][c1-1]+k[r1-1][c1-1];
		data-=k[r2][c1]-k[r2][c1-1]-k[r1-1][c1]+k[r1-1][c1-1];
		data-=k[r2][c2]-k[r2][c1-1]-k[r2-1][c2]+k[r2-1][c1-1];
		data-=k[r2][c2]-k[r2][c2-1]-k[r1-1][c2]+k[r1-1][c2-1];
		data+=k[r1][c1]-k[r1-1][c1]-k[r1][c1-1]+k[r1-1][c1-1];
		data+=k[r1][c2]-k[r1-1][c2]-k[r1][c2-1]+k[r1-1][c2-1];
		data+=k[r2][c1]-k[r2-1][c1]-k[r2][c1-1]+k[r2-1][c1-1];
		data+=k[r2][c2]-k[r2-1][c2]-k[r2][c2-1]+k[r2-1][c2-1];

		printf("%d\n", data);
	}

	for(int i=0;i<=N;++i)
		free(k[i]);
	free(k);
	return 0;
}