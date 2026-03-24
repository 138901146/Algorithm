#include<stdio.h>

int main(void)
{
	int S, A, B, total=250;

	scanf("%d", &S);
	scanf("%d", &A);
	scanf("%d", &B);

	S=S<A?0:S-A;

	if(S%B)
		total+=100*(S/B+1);
	else
		total+=100*S/B;

	printf("%d", total);
	return 0;
}