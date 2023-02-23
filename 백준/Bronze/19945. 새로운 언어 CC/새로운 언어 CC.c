#include<stdio.h>

int main(void)
{
	int n, bit=1, count=0;

	scanf("%d", &n);

	if(n<0)
		printf("32\n");
	else if(n<2)
		printf("1\n");
	else
	{
		while(bit<=n)
		{
			count++;
			bit*=2;
		}

		printf("%d\n", count);
	}

	return 0;
}