#include<stdio.h>

int main(void)
{
	int n, sum=0;

	scanf("%d", &n);

	while(n)
	{
		int digit=n%10;
		sum+=digit*digit*digit*digit*digit;
		n/=10;
	}

	printf("%d", sum);
	return 0;
}