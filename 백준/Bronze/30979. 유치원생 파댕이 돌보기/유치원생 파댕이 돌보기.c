#include<stdio.h>

int main(void)
{
	int T, N, F, sum=0;

	scanf("%d", &T);
	scanf("%d", &N);

	while(N--)
	{
		scanf("%d", &F);
		sum+=F;
	}

	printf("%s", sum>=T?"Padaeng_i Happy":"Padaeng_i Cry");
	return 0;
}