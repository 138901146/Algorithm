#include<stdio.h>

int main(void)
{
	int N, member[51][51], max[51]={0}, max_index=1, count=1, x, y;

	scanf("%d", &N);

	for(int i=1;i<=N;++i)
	{
		for(int j=1;j<=N;++j)
			member[i][j]=100;
		member[i][i]=0;
	}

	scanf("%d%d", &x, &y);

	while(x!=-1 || y!=-1)
	{
		member[x][y]=member[y][x]=1;
		scanf("%d%d", &x, &y);
	}

	for(int mid=1;mid<=N;++mid)
		for(int start=1;start<=N;++start)
			for(int end=1;end<=N;++end)
				if(member[start][end]>member[start][mid]+member[mid][end])
					member[start][end]=member[start][mid]+member[mid][end];

	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)
			max[i]=member[i][j]>max[i]?member[i][j]:max[i];

	for(int n=2;n<=N;++n)
		if(max[n]<max[max_index])
		{
			count=1;
			max_index=n;
		}
		else if(max[n]==max[max_index])
			++count;

	printf("%d %d\n", max[max_index], count);
	printf("%d", max_index);
	for(int n=max_index+1;n<=N;++n)
		if(max[n]==max[max_index])
			printf(" %d", n);

	return 0;
}