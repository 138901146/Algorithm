#include<stdio.h>

int main(void)
{
	int T, n;

	scanf("%d", &T);

	for(int t=0;t<T;t++)
	{
		long int combination=1;

		scanf("%d", &n);

		for(int N=n+9,r=0;r<9;N--,r++)
			combination*=N;
		for(int r=2;r<10;r++)
			combination/=r;

		printf("%ld\n", combination);
	}

	return 0;
}