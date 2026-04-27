#include<stdio.h>

int main(void)
{
	int N, X, S, c, p;

	scanf("%d", &N);
	scanf("%d%d", &X, &S);

	while(N--)
	{
		scanf("%d%d", &c, &p);

		if(c<=X && S<p)
		{
			printf("YES");
			return 0;
		}
	}

	printf("NO");
	return 0;
}