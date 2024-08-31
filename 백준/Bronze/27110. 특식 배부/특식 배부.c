#include<stdio.h>

int min(int x,int y)
{
	return x<y?x:y;
}

int main(void)
{
	int N, A, B, C;

	scanf("%d", &N);
	scanf("%d%d%d", &A, &B, &C);

	printf("%d", min(N,A)+min(N,B)+min(N,C));
	return 0;
}