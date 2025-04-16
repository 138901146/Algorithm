#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	int N, M, count=0, x, y;
	bool eww[201][201]={false};

	scanf("%d%d", &N, &M);
	while(M--)
	{
		scanf("%d%d", &x, &y);
		eww[x][y]=eww[y][x]=true;
	}

	for(int i=1;i<=N;++i)
		for(int j=i+1;j<=N;++j)
		{
			if(eww[i][j])
				continue;
			for(int k=j+1;k<=N;++k)
				if(!eww[i][k] && !eww[j][k])
					++count;
		}

	printf("%d", count);
	return 0;
}