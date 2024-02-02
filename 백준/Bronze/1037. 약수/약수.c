#include<stdio.h>

int main(void)
{
	int count;
	long long A, max=0, min=10000000;

	scanf("%d", &count);

	while(count--)
	{
		scanf("%lld", &A);

		max=A>max?A:max;
		min=A<min?A:min;
	}

	printf("%lld", max*min);
	return 0;
}