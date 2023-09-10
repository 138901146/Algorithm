#include<stdio.h>

int main(void)
{
	int A, B, K, X, count=0;

	scanf("%d%d", &A, &B);
	scanf("%d%d", &K, &X);

	for(int i=K-X;i<=K+X;++i)
		count+=A<=i && i<=B;

	if(count==0)
		printf("IMPOSSIBLE");
	else
		printf("%d", count);

	return 0;
}