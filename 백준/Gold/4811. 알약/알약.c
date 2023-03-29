#include<stdio.h>

int main(void)
{
	int N;
	long long method[31][31]={0, };

	for(int i=1;i<31;i++)
	{
		method[i][0]=1;
		for(int j=1;j<=i;j++)
			method[i][j]+=method[i-1][j]+method[i][j-1];
	}

	scanf("%d", &N);
	while(N>0)
	{
		printf("%lld\n", method[N][N]);
		scanf("%d", &N);
	}

	return 0;
}