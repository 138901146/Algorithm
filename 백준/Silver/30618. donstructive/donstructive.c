#include<stdio.h>

int main(void)
{
	int N;

	scanf("%d", &N);

	for(int i=1;i<=N;i+=2)
		printf("%d ", i);
	for(int i=N-(N&1);0<i;i-=2)
		printf("%d ", i);

	return 0;
}