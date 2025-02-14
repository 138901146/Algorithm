#include<stdio.h>

int main(void)
{
	unsigned long long a, b, x, y;

	scanf("%llu%llu", &a, &b);

	x=(a&1)*b;
	y=a*(b&1);

	printf("%llu", x<y?x:y);
	return 0;
}