#include<stdio.h>
#include<string.h>

int main(void)
{
	char A[21]={0}, B[21]={0};

	scanf("%s", A);
	scanf("%s", B);

	printf("%d", strcmp(A,B)?1550:0);
	return 0;
}