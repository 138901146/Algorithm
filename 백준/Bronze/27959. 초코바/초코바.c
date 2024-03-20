#include<stdio.h>

int main(void)
{
	int N, M;

	scanf("%d%d", &N, &M);

	printf("%s", N*100<M?"No":"Yes");
	return 0;
}