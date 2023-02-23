#include<stdio.h>

int main(void)
{
	int A, B;

	scanf("%d %d", &A, &B);

	A=A/100+10*(A/10%10)+100*(A%10);
	B=B/100+10*(B/10%10)+100*(B%10);

	printf("%d\n", A>B?A:B);

	return 0;
}