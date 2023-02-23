#include<stdio.h>

int main(void)
{
	int L;

	scanf("%d", &L);

	printf("%d\n", L/5+(L%5!=0));
	return 0;
}