#include<stdio.h>

int stair[100][10][1024]={0, };

int main(void)
{
	int N, sum=0;

	scanf("%d", &N);

	for(int i=1;i<10;++i)
		stair[0][i][1<<i]=1;

	for(int n=1;n<N;++n)
		for(int i=0;i<10;++i)
			for(int j=1;j<1024;++j)
			{
				if(i)
					stair[n][i][j|(1<<i)]=(stair[n][i][j|(1<<i)]+stair[n-1][i-1][j])%1000000000;
				if(i<9)
					stair[n][i][j|(1<<i)]=(stair[n][i][j|(1<<i)]+stair[n-1][i+1][j])%1000000000;
			}

	for(int i=0;i<10;++i)
		sum=(sum+stair[N-1][i][1023])%1000000000;

	printf("%d", sum);
	return 0;
}