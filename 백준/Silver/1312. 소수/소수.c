#include<stdio.h>

int main(void)
{
	int A, B, N, ans;

	scanf("%d%d%d", &A, &B, &N);

	A%=B;
	while(N--)
	{
		A*=10;
		ans=A/B;
		A-=A/B*B;
	}

	printf("%d", ans);
	return 0;
}