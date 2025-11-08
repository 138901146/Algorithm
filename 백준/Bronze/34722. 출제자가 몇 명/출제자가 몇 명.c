#include<stdio.h>

int main(void)
{
	int N, s, c, a, r, count=0;

	scanf("%d", &N);

	while(N--)
	{
		scanf("%d%d%d%d", &s, &c, &a, &r);
		count+=999<s||1599<c||1499<a||(r!=-1&&r<31);
	}

	printf("%d", count);
	return 0;
}