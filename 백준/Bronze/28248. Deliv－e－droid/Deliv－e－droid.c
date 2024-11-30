#include<stdio.h>

int main(void)
{
	int P, C, F=0;

	scanf("%d", &P);
	scanf("%d", &C);

	if(C<P)
		F=500;

	F+=50*P;
	F-=10*C;

	printf("%d", F);
	return 0;
}