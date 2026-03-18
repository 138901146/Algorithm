#include<stdio.h>

int main(void)
{
	int N, x, count=0;

	scanf("%d", &N);

	while(N--)
	{
		getchar();
		scanf("D-%d", &x);
		count+=x<91;
	}

	printf("%d", count);
	return 0;
}