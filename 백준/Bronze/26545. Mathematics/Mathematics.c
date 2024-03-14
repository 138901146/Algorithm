#include<stdio.h>

int main(void)
{
	int n, number, sum=0;

	scanf("%d", &n);

	while(n--)
	{
		scanf("%d", &number);
		sum+=number;
	}

	printf("%d", sum);
	return 0;
}