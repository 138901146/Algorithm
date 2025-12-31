#include<stdio.h>

int main(void)
{
	int d1, d2, sum=0, current=0;

	scanf("%d%d", &d1, &d2);

	current=(d1+d2-1)&3;

	scanf("%d%d", &d1, &d2);
	current+=(d1+d2)&3;

	printf("%d", ((current+3)&3)+1);
	return 0;
}