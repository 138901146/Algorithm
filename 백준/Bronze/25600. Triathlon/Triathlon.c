#include<stdio.h>

int main(void)
{
	int max=0, N, a, d, g;

	scanf("%d", &N);

	while(N--)
	{
		scanf("%d%d%d", &a, &d, &g);

		a<<=a==d+g;
		max=a*(d+g)<max?max:a*(d+g);
	}

	printf("%d", max);
	return 0;
}