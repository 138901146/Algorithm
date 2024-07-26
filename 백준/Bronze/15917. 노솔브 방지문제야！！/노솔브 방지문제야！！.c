#include<stdio.h>

int main(void)
{
	int Q, a;

	scanf("%d", &Q);

	while(Q--)
	{
		scanf("%d", &a);
		printf("%d\n", (a&-a)==a);
	}

	return 0;
}