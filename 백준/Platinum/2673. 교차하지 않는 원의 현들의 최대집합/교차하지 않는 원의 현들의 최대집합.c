#include<stdio.h>

int main(void)
{
	int N, max[101][101]={0}, connected[101][101]={0}, start, end;

	scanf("%d", &N);

	while(N--)
	{
		scanf("%d%d", &start, &end);
		connected[start][end]=connected[end][start]=1;
	}

	for(int i=1;i<101;++i)
		for(int j=i;j;--j)
			for(int k=j;k<i;++k)
				max[j][i]=max[j][k]+max[k][i]+connected[i][j]<max[j][i]?max[j][i]:max[j][k]+max[k][i]+connected[i][j];

	printf("%d", max[1][100]);
	return 0;
}