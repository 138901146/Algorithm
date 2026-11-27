#include<stdio.h>
#include<string.h>

int main(void)
{
	int N, M, K, current=0, next=1, count[100][100][2]={0}, dr[4]={-1,0,0,1}, dc[4]={0,-1,1,0}, total=0, length;
	char board[100][101]={0}, word[81]={0};

	scanf("%d%d%d", &N, &M, &K);

	for(int r=0;r<N;++r)
		scanf("%s", board[r]);
	scanf("%s", word);

	length=strlen(word);
	for(int r=0;r<N;++r)
		for(int c=0;c<M;++c)
			if(board[r][c]==word[0])
				count[r][c][0]=1;

	for(int i=0;i<length-1;++i,current^=1,next^=1)
	{
		for(int r=0;r<N;++r)
			for(int c=0;c<M;++c)
				count[r][c][next]=0;

		for(int r=0;r<N;++r)
			for(int c=0;c<M;++c)
				if(board[r][c]==word[i])
					for(int j=0;j<4;++j)
						for(int k=1;k<=K;++k)
						{
							int next_r=r+k*dr[j], next_c=c+k*dc[j];

							if(next_r<0||N<=next_r||next_c<0||M<=next_c||board[next_r][next_c]!=word[i+1])
								continue;

							count[next_r][next_c][next]+=count[r][c][current];
						}
	}

	for(int r=0;r<N;++r)
		for(int c=0;c<M;++c)
			total+=count[r][c][current];

	printf("%d", total);
	return 0;
}