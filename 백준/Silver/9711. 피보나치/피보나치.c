#include<stdio.h>

int main(void)
{
	int T, P, Q;

	scanf("%d", &T);

	for(int x=1;x<=T;++x)
	{
		long long fibonacci[10001]={0,1};

		scanf("%d%d", &P, &Q);

		for(int i=2;i<=P;++i)
			fibonacci[i]=(fibonacci[i-1]+fibonacci[i-2])%Q;

		printf("Case #%d: %lld\n", x, fibonacci[P]%Q);
	}

	return 0;
}