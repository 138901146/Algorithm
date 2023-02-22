#include<stdio.h>

int main(void)
{
	long int D[21]={1,0,1,2,};
	int T, N;

	for(int n=4;n<21;n++)
		D[n]=(n-1)*(D[n-1]+D[n-2]);

	scanf("%d", &T);

	for(int t=0;t<T;t++)
	{
		scanf("%d", &N);
		printf("%ld\n", D[N]);
	}

	return 0;
}