#include<stdio.h>

int main(void)
{
	int R;

	scanf("%d", &R);

	printf("%lf\n%lf\n", 3.141592653589*R*R, (double)2*R*R);
	return 0;
}