#include<stdio.h>

int main(void)
{
	int N, count=1;

	scanf("%d", &N);

	while(count*count<=N)
		count++;

	printf("%d\n", count-1);
	return 0;
}