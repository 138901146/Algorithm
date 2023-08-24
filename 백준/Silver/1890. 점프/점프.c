#include<stdio.h>

int main(void)
{
	int N, jump;
	unsigned long long route[100][100]={0, };

	scanf("%d", &N);

	route[0][0]=1;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			scanf("%d", &jump);

			if(i==N-1 && j==N-1)
				break;
			if(i+jump<N)
				route[i+jump][j]+=route[i][j];
			if(j+jump<N)
				route[i][j+jump]+=route[i][j];
		}

	printf("%llu\n", route[N-1][N-1]);
	return 0;
}