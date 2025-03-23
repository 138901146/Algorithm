#include<stdio.h>

int main(void)
{
	int L, R, A;

	scanf("%d%d%d", &L, &R, &A);

	while(A--)
		L<R?++L:++R;

	printf("%d", (L<R?L:R)<<1);
	return 0;
}