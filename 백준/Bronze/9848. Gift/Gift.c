#include<stdio.h>

int main(void)
{
	int n, k, t, expect, count=0;

	scanf("%d%d", &n, &k);

	scanf("%d", &t);

	while(--n)
	{
		expect=t-k;
		scanf("%d", &t);
		count+=t<=expect;
	}

	printf("%d", count);
	return 0;
}