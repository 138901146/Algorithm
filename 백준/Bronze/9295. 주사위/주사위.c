#include<stdio.h>

int main(void)
{
	int T, A, B;

	scanf("%d", &T);
	for(int x=1;x<=T;x++)
	{
		scanf("%d%d", &A, &B);
		printf("Case %d: %d\n", x, A+B);
	}

	return 0;
}