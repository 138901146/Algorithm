#include<stdio.h>

int main(void)
{
	int L, A, B, C, D;

	scanf("%d", &L);
	scanf("%d", &A);
	scanf("%d", &B);
	scanf("%d", &C);
	scanf("%d", &D);

	A=A%C==0?A/C:A/C+1;
	B=B%D==0?B/D:B/D+1;

	printf("%d\n", A>B?L-A:L-B);

	return 0;
}