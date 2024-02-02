#include<stdio.h>

int main(void)
{
	int T, A, B, lcm;

	scanf("%d", &T);

	while(T--)
	{
		scanf("%d%d", &A, &B);

		lcm=A*B;
		while(B)
		{
			int temp=A%B;
			A=B;
			B=temp;
		}

		printf("%d\n", lcm/A);
	}

	return 0;
}