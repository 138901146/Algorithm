#include<stdio.h>

int main(void)
{
	int L, N;
	char x;

	scanf("%d", &L);

	while(L--)
	{
		scanf("%d %c", &N, &x);

		while(N--)
			printf("%c", x);
		printf("\n");
	}

	return 0;
}