#include<stdio.h>

int main(void)
{
	int A;

	scanf("%d", &A);

	for(int n=1;n<=A;n++)
		if(30%(n+1)==0)
			printf("%d\n", n);

	return 0;
}