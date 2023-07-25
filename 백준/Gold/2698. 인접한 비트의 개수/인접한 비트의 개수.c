#include<stdio.h>

int S[101][101][101]={0, }, count[101][101]={0, };

int main(void)
{
	int T, n, k;

	S[1][0][0]=S[1][0][1]=1;
	count[1][0]=2;

	for(int i=2;i<101;i++)
		for(int j=0;j<i;j++)
		{
			S[i][j][0]=count[i-1][j];
			S[i][j][1]=S[i-1][j][0];
			count[i][j]=S[i][j][0]+S[i][j][1];
			if(j)
			{
				int bound=j+1<=i?j+1:i;
				for(int k=2;k<=bound;k++)
				{
					S[i][j][k]=S[i-1][j-1][k-1];
					count[i][j]+=S[i][j][k];
				}
			}
		}

	scanf("%d", &T);
	for(int t=0;t<T;t++)
	{
		scanf("%d%d", &n, &k);
		printf("%d\n", count[n][k]);
	}

	return 0;
}