#include<stdio.h>

int main(void)
{
	int n, a, odd=0, even=0;

	scanf("%d", &n);

	while(n--)
	{
		scanf("%d", &a);

		if(a&1)
			++odd;
		else
			++even;
	}

	printf("%s", odd<even?"Happy":"Sad");
	return 0;
}