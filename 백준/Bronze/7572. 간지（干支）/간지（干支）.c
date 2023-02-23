#include<stdio.h>

int main(void)
{
	int N;

	scanf("%d", &N);

	printf("%c%d\n", 'A'+(N+8)%12, (N+6)%10);

	return 0;
}