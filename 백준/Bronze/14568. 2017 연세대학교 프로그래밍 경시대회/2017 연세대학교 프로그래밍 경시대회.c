#include<stdio.h>

int main(void)
{
	int N, count=0;

	scanf("%d", &N);

	for(int th=2;th+4<=N;th+=2)
		for(int yh=1;2*yh+2+th<=N;yh++)
			count+=N-th-yh>=yh+2;

	printf("%d\n", count);
	return 0;
}