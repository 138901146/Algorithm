#include<stdio.h>

char star[397][398]={0};

void star_function(int r,int c,int N)
{
	if(N==1)
	{
		star[r][c]='*';
		return;
	}

	for(int i=0;i<4*N-3;++i)
	{
		star[r][c+i]='*';
		star[r+4*(N-1)][c+i]='*';
		star[r+i][c]='*';
		star[r+i][c+4*(N-1)]='*';
	}

	star_function(r+2,c+2,N-1);
}

int main(void)
{
	int N;

	scanf("%d", &N);

	for(int i=0;i<4*N-3;++i)
		for(int j=0;j<4*N-3;++j)
			star[i][j]=' ';

	star_function(0,0,N);

	for(int i=0;i<4*N-3;++i)
		printf("%s\n", star[i]);
	return 0;
}