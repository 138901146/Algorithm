#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, K;
	char **mirror=NULL;

	scanf("%d", &N);
	mirror=(char **)malloc(N*sizeof(char *));
	for(int i=0;i<N;i++)
		mirror[i]=(char *)calloc(N+1,sizeof(char));

	for(int i=0;i<N;i++)
		scanf("%s", mirror[i]);
	scanf("%d", &K);

	if(K==1)
		for(int i=0;i<N;i++)
			printf("%s\n", mirror[i]);
	else if(K==2)
		for(int i=0;i<N;i++)
		{
			for(int j=N-1;j>=0;j--)
				printf("%c", mirror[i][j]);
			printf("\n");
		}
	else
		for(int i=N-1;i>=0;i--)
			printf("%s\n", mirror[i]);

	for(int i=0;i<N;i++)
		free(mirror[i]);
	free(mirror);
	return 0;
}