#include<stdio.h>

int main(void)
{
	int B;

	scanf("%d", &B);

	B=B*5-400;

	printf("%d\n%d", B, B<100?1:100<B?-1:0);
	return 0;
}