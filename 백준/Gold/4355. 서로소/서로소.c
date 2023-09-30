#include<stdio.h>

int main(void)
{
	int n;

	scanf("%d", &n);

	while(n)
	{
		if(n==1)
			printf("0\n");
		else
		{
			int phi=n;

			for(int i=2;i*i<=n;++i)
			{
				if(!(n%i))
					phi=phi/i*(i-1);
				while(!(n%i))
					n/=i;
			}

			printf("%d\n", n==1?phi:phi/n*(n-1));
		}

		scanf("%d", &n);
	}

	return 0;
}