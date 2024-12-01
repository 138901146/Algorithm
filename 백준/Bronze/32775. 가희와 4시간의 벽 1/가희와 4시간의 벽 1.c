#include<stdio.h>

int main(void)
{
	int S, F;

	scanf("%d", &S);
	scanf("%d", &F);

	printf("%s", F<S?"flight":"high speed rail");
	return 0;
}