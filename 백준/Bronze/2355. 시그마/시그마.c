#include<stdio.h>

int main(void)
{
	long double A, B;

	scanf("%Lf %Lf", &A, &B);

	if(A>B)
	{
		long double temp=A;
		A=B;
		B=temp;
	}

	printf("%.0Lf\n", (B-A)*(B-A+1)/2+(B-A+1)*A);
	return 0;
}