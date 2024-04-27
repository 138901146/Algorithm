#include<stdio.h>
#include<math.h>

int main(void)
{
	int A, B;

	scanf("%d%d", &A, &B);

	if(A*A==B)
		printf("%d", -A);
	else
	{
		int root=sqrt(A*A-B);
		printf("%d %d", -A-root, root-A);
	}

	return 0;
}