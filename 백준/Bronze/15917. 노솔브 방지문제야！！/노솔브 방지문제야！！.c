#include<stdio.h>

int main(void)
{
	int Q;
	long long a;

	scanf("%d", &Q);

	while(Q--)
	{
		scanf("%lld", &a);

		while(a)
		{
			if(a&1)
				break;

			a>>=1;
		}

		printf("%d\n", a==1);
	}

	return 0;
}