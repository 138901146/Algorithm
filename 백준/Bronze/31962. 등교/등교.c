#include<stdio.h>

int main(void)
{
	int N, X, S, T, best=0;

	scanf("%d%d", &N, &X);

	while(N--)
	{
		scanf("%d%d", &S, &T);

		if(S+T<=X && best<S)
			best=S;
	}

	printf("%d", best?best:-1);
	return 0;
}