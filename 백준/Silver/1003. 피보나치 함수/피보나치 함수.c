#include<stdio.h>

int main(void)
{
	long long int fibonacci[41][2];
	int T;

	for(int i=0;i<41;i++)
		fibonacci[i][0]=fibonacci[i][1]=0;

	fibonacci[2][0]=fibonacci[2][1]=fibonacci[0][0]=fibonacci[1][1]=1;

	for(int i=3;i<41;i++)
		for(int j=0;j<2;j++)
			fibonacci[i][j]=fibonacci[i-1][j]+fibonacci[i-2][j];

	scanf("%d", &T);

	for(int t=0;t<T;t++)
	{
		int N;

		scanf("%d", &N);

		printf("%lld %lld\n", fibonacci[N][0], fibonacci[N][1]);
	}

	return 0;
}