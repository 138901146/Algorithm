#include<stdio.h>

#define MOD 1000000009

int count[1001][1001]={1, 0,};

int main(void)
{
	int T, n, m, sum;

	scanf("%d", &T);

	while(T--)
	{
		scanf("%d%d", &n, &m);

		sum=0;

		if(count[n][m])
		{
			for(int i=0;i<=m;++i)
				sum=(sum+count[n][i])%MOD;
			printf("%d\n", sum);
			continue;
		}

		for(int i=1;i<=n;++i)
			for(int j=1;j<=i&&j<=m;++j)
			{
				count[i][j]=0;
				for(int k=1;k<=3;++k)
					if(0<=i-k)
						count[i][j]=(count[i][j]+count[i-k][j-1])%MOD;
			}

		for(int i=0;i<=m;++i)
			sum=(sum+count[n][i])%MOD;

		printf("%d\n", sum);
	}

	return 0;
}