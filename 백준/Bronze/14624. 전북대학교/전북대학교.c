#include<stdio.h>

void print(int N)
{
	int current=N>>1;
	char symbol[50][51]={0};

	for(int i=0;i<N;++i)
		symbol[0][i]='*';

	for(int i=0;i<N>>1;++i)
		symbol[1][i]=' ';
	symbol[1][N>>1]='*';

	for(int i=2;i<N+3>>1;++i)
	{
		for(int j=0;j<(N>>1)+i-1;++j)
			symbol[i][j]=' ';
		symbol[i][(N>>1)+i-1]=symbol[i][(N>>1)-i+1]='*';
	}

	for(int i=0;i<N+3>>1;++i)
		printf("%s\n", symbol[i]);

}

int main(void)
{
	int N;

	scanf("%d", &N);

	if(N&1)
		print(N);
	else
		printf("I LOVE CBNU");

	return 0;
}