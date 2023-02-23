#include<stdio.h>

int main(void)
{
	int N, count, bound=1;

	scanf("%d", &N);

	for(count=1;bound<N;count++)
		bound+=6*count;

	printf("%d\n", count);

	return 0;
}