#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, heart[2]={-1,-1}, size[5]={0, };
	char **square=NULL;

	scanf("%d", &N);
	square=(char **)malloc(N*sizeof(char *));
	for(int n=0;n<N;n++)
	{
		square[n]=(char *)calloc(N+1,sizeof(char));
		scanf("%s", square[n]);
	}

	for(int i=0;heart[0]==-1&&heart[1]==-1;i++)
		for(int j=0;j<N;j++)
			if(square[i][j]=='*')
			{
				heart[0]=i+1;
				heart[1]=j;
				break;
			}

	for(int n=1;heart[1]-n>=0 && square[heart[0]][heart[1]-n]=='*';n++)
		size[0]++;
	for(int n=heart[1]+1;n<N && square[heart[0]][n]=='*';n++)
		size[1]++;
	for(int n=heart[0]+1;n<N && square[n][heart[1]]=='*';n++)
		size[2]++;
	for(int n=heart[0]+size[2]+1;n<N && square[n][heart[1]-1]=='*';n++)
		size[3]++;
	for(int n=heart[0]+size[2]+1;n<N && square[n][heart[1]+1]=='*';n++)
		size[4]++;

	printf("%d %d\n", heart[0]+1, heart[1]+1);
	for(int i=0;i<5;i++)
		printf("%d ", size[i]);
	printf("\n");
	for(int n=0;n<N;n++)
		free(square[n]);
	free(square);
	return 0;
}