#include<stdio.h>

int main(void)
{
	int AB;

	scanf("%d", &AB);

	printf("%d\n", AB%10==0?AB/100+10:AB/10+AB%10);
	return 0;
}