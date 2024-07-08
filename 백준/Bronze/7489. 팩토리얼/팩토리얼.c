#include<stdio.h>

int main(void)
{
	int t;

	scanf("%d", &t);

	while(t--)
	{
		int n, factorial=1;

		scanf("%d", &n);

		for(int i=1;i<=n;++i)
		{
			factorial%=10000;
			factorial*=i;

			while(!(factorial%10))
				factorial/=10;
		}

		printf("%d\n", factorial%10);
	}

	return 0;
}