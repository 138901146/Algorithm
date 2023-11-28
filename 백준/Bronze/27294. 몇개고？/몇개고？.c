#include<stdio.h>

int main(void)
{
	int T, S;

	scanf("%d%d", &T, &S);

	printf("%d", (S||!(12<=T&&T<=16))?280:320);
	return 0;
}