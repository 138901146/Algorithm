#include<stdio.h>

int main(void)
{
	int n, count=0;

	scanf("%d", &n);

	for(int i=0;i<100;++i)
		count+=0<=n-i&&n-i<100;

	printf("%d", count);
	return 0;
}