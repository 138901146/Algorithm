#include<stdio.h>

int main(void)
{
	long int A, B, C, X1, X2, Y1, Y2;

	scanf("%ld %ld %ld", &A, &B, &C);
	scanf("%ld %ld %ld %ld", &X1, &X2, &Y1, &Y2);

	if(A==0)
		printf("%s\n", (B*Y1+C)*(B*Y2+C)<0?"Poor":"Lucky");
	else if(B==0)
		printf("%s\n", (A*X1+C)*(A*X2+C)<0?"Poor":"Lucky");
	else if(A*B<0)
		printf("%s\n", (A*X1+B*Y2+C)*(A*X2+B*Y1+C)<0?"Poor":"Lucky");
	else
		printf("%s\n", (A*X1+B*Y1+C)*(A*X2+B*Y2+C)<0?"Poor":"Lucky");
	return 0;
}