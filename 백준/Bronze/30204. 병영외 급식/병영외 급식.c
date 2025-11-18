#include<stdio.h>

int main(void)
{
	int N, X, p, mod=0;

	scanf("%d%d", &N, &X);

	while(N--)
	{
		scanf("%d", &p);
		mod=(mod+p)%X;
	}

	printf("%d", !mod);
	return 0;
}