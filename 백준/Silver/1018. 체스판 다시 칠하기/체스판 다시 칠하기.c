#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, M, min=64;
	char **board=NULL;

	scanf("%d %d", &N, &M);
	board=(char **)malloc(N*sizeof(char *));
	for(int i=0;i<N;i++)
	{
		board[i]=(char *)calloc(M+1,sizeof(char));
		scanf("%s", board[i]);
	}

	for(int i=0;i+7<N;i++)
		for(int j=0;j+7<M;j++)
		{
			int difference, white=0, black=0;

			for(int x=0;x<8;x++)
				for(int y=0;y<8;y++)
				{
					white+=(x+y)%2==0?board[i+x][j+y]=='W':board[i+x][j+y]=='B';
					black+=(x+y)%2==0?board[i+x][j+y]=='B':board[i+x][j+y]=='W';
				}

			difference=white<black?white:black;
			min=difference<min?difference:min;
		}

	printf("%d\n", min);
	for(int i=0;i<N;i++)
		free(board[i]);
	free(board);
	return 0;
}