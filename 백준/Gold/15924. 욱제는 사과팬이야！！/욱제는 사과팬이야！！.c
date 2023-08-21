#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, M, **route=NULL, sum=0;
	char **pattern=NULL;

	scanf("%d%d", &N, &M);
	route=(int **)malloc((N+1)*sizeof(int *));
	pattern=(char **)malloc(N*sizeof(char *));

	for(int n=0;n<N;n++)
	{
		route[n]=(int *)calloc(M+1,sizeof(int));
		pattern[n]=(char *)calloc(M+1,sizeof(char));

		getchar();
		scanf("%s", pattern[n]);
	}
	route[N]=(int *)calloc(M+1,sizeof(int));

	for(int n=N;n>0;n--)
		for(int m=M;m>0;m--)
		{
			switch(pattern[n-1][m-1])
			{
				case 'B':
					route[n-1][m-1]=(route[n][m-1]+route[n-1][m])%1000000009;
					break;
				case 'S':
					route[n-1][m-1]=route[n][m-1]%1000000009;
					break;
				case 'E':
					route[n-1][m-1]=route[n-1][m]%1000000009;
					break;
				default:
					route[n-1][m-1]=1;
			}
			sum=(sum+route[n-1][m-1])%1000000009;
		}

	printf("%d\n", sum);
	for(int n=0;n<N;n++)
	{
		free(route[n]);
		free(pattern[n]);
	}
	free(route[N]);
	free(route);
	free(pattern);
	return 0;
}