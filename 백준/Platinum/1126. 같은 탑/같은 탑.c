#include<stdio.h>

int top[500001][51];

int main(void)
{
	int N, block[50];

	scanf("%d", &N);

	for(int i=0;i<N;++i)
		scanf("%d", &block[i]);

	for(int i=0;i<500001;++i)
		for(int j=0;j<51;++j)
			top[i][j]=-1;
	top[0][0]=0;
	top[block[0]][0]=block[0];

	for(int i=1;i<N;++i)
		for(int j=0;j<500001;++j)
			if(-1<top[j][i-1])
			{
				top[j][i]=top[j][i]<top[j][i-1]?top[j][i-1]:top[j][i];

				if(block[i]+top[j][i-1]<500001)
					top[j+block[i]][i]=top[j+block[i]][i]<block[i]+top[j][i-1]?block[i]+top[j][i-1]:top[j+block[i]][i];

				if(0<block[i]-j && block[i]-j<500001)
					top[block[i]-j][i]=top[block[i]-j][i]<top[j][i-1]+block[i]-j?top[j][i-1]+block[i]-j:top[block[i]-j][i];
				else
					top[j-block[i]][i]=top[j-block[i]][i]<top[j][i-1]?top[j][i-1]:top[j-block[i]][i];
			}

	printf("%d", top[0][N-1]?top[0][N-1]:-1);
	return 0;
}