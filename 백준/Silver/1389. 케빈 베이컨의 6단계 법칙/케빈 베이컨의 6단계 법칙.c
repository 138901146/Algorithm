#include<stdio.h>

int main(void)
{
	int N, M, A, B, friend[101][101], min_sum=1000000, min;

	scanf("%d%d", &N, &M);

	for(int i=1;i<=N;++i)
	{
		for(int j=1;j<=N;++j)
			friend[i][j]=500;
		friend[i][i]=0;
	}

	while(M--)
	{
		scanf("%d%d", &A, &B);
		friend[A][B]=friend[B][A]=1;
	}


	for(int mid=1;mid<=N;++mid)
		for(int start=1;start<=N;++start)
			for(int end=1;end<=N;++end)
				if(friend[start][end]>friend[start][mid]+friend[mid][end])
					friend[start][end]=friend[start][mid]+friend[mid][end];

	for(int i=1;i<=N;++i)
	{
		int sum=0;

		for(int j=1;j<=N;++j)
			sum+=friend[i][j];

		if(sum<min_sum)
		{
			min_sum=sum;
			min=i;
		}
	}

	printf("%d", min);
	return 0;
}