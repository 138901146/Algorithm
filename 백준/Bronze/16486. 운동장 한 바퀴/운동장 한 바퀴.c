#include<stdio.h>

int main(void)
{
	int d1, d2;

	scanf("%d", &d1);
	scanf("%d", &d2);

	printf("%lf\n", (double)2*(3.141592*d2+d1));
	return 0;
}