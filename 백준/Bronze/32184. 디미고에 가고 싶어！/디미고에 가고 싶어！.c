#include<stdio.h>

int main(void)
{
	int A, B, count=1;

	scanf("%d%d", &A, &B);

	if(!(A&1))
	{
		++count;
		++A;
	}

	if(B&1)
	{
		++count;
		--B;
	}

	printf("%d", (B-A>>1)+count);
	return 0;
}