#include<stdio.h>

int N, max=0;
char candy[50][51]={0};

void simulate(void)
{
	for(int i=0;i<N;++i)
	{
		int r=1, c=1;

		for(int j=1;j<N;++j)
		{
			c=candy[i][j]==candy[i][j-1]?c+1:1;
			r=candy[j][i]==candy[j-1][i]?r+1:1;

			max=r<max?max:r;
			max=c<max?max:c;
		}
	}
}

int main(void)
{
	scanf("%d", &N);
	for(int n=0;n<N;++n)
		scanf("%s", candy[n]);

	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
		{
			if(i+1<N&&candy[i][j]!=candy[i+1][j])
			{
				char temp=candy[i][j];
				candy[i][j]=candy[i+1][j];
				candy[i+1][j]=temp;
				simulate();
				candy[i+1][j]=candy[i][j];
				candy[i][j]=temp;
			}
			if(j+1<N&&candy[i][j]!=candy[i][j+1])
			{
				char temp=candy[i][j];
				candy[i][j]=candy[i][j+1];
				candy[i][j+1]=temp;
				simulate();
				candy[i][j+1]=candy[i][j];
				candy[i][j]=temp;
			}
		}

	printf("%d", max);
	return 0;
}