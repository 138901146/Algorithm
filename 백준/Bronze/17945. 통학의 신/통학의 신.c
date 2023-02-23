#include<stdio.h>
#include<math.h>

int main(void)
{
	int A, B;

	scanf("%d %d", &A, &B);

	if(A*A==B)
		printf("%d\n", -A);
	else
		printf("%d %d\n", -A-(int)sqrt(A*A-B), (int)sqrt(A*A-B)-A);

	return 0;
}