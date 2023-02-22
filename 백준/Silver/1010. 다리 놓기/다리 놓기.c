#include<stdio.h>

int main(void)
{
	long double factorial[30]={1.0, };
	int T;

	for(int i=1;i<30;i++)
		factorial[i]=i*factorial[i-1];

	scanf("%d", &T);

	for(int t=0;t<T;t++)
	{
		int N, M;

		scanf("%d %d", &N, &M);

		printf("%.0Lf\n",factorial[M]/(factorial[N]*factorial[M-N]));
	}

	return 0;
}