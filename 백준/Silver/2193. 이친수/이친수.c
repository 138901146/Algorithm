#include<stdio.h>

int main(void)
{
	long int pinary[2][90]={0, };
	int N;

	scanf("%d", &N);

	pinary[1][0]=1;
	for(int n=1;n<N;n++)
	{
		pinary[1][n]=pinary[0][n-1];
		pinary[0][n]=pinary[0][n-1]+pinary[1][n-1];
	}

	printf("%ld\n", pinary[0][N-1]+pinary[1][N-1]);
	return 0;
}