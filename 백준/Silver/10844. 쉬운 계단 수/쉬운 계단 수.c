#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, **stairs=NULL, sum=0;

	scanf("%d", &N);
	stairs=(int **)malloc((N+1)*sizeof(int *));
	for(int n=0;n<=N;n++)
		stairs[n]=(int *)calloc(10,sizeof(int));

	for(int i=1;i<10;i++)
		stairs[1][i]=1;
	for(int n=2;n<=N;n++)
	{
		stairs[n][0]=stairs[n-1][1];
		for(int i=1;i<9;i++)
			stairs[n][i]=(stairs[n-1][i-1]+stairs[n-1][i+1])%1000000000;
		stairs[n][9]=stairs[n-1][8];
	}

	for(int i=0;i<10;i++)
		sum=(sum+stairs[N][i])%1000000000;

	printf("%d\n", sum);
	for(int n=0;n<=N;n++)
		free(stairs[n]);
	free(stairs);
	return 0;
}