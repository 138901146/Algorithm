#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	int N, max=0;
	char map[50][51]={0};
	bool friend[50][50]={false};

	scanf("%d", &N);

	for(int n=0;n<N;++n)
		scanf("%s", map[n]);

	for(int i=0;i<N;++i)
	{
		int count=0;

		for(int j=0;j<N;++j)
			if(map[i][j]=='Y')
			{
				friend[i][j]=true;
				for(int k=0;k<N;++k)
					friend[i][k]|=map[j][k]=='Y';
			}

		friend[i][i]=false;

		for(int j=0;j<N;++j)
			count+=friend[i][j];
		max=count<max?max:count;
	}

	printf("%d", max);
	return 0;
}