#include<stdio.h>

int main(void)
{
	int A, P;

	scanf("%d%d", &A, &P);

	A*=7;
	P*=13;

	printf("%s", A<P?"Petra":A>P?"Axel":"lika");
	return 0;
}