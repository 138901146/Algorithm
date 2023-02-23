#include<stdio.h>

int main(void)
{
	int n;

	scanf("%d", &n);

	while(n!=-1)
	{
		int sum=0;

		for(int i=1;i*2<=n;i++)
			if(n%i==0)
				sum+=i;

		if(sum==n)
		{
			printf("%d = 1", n);

			for(int i=2;i*2<=n;i++)
				if(n%i==0)
					printf(" + %d", i);
			printf("\n");
		}
		else
			printf("%d is NOT perfect.\n", n);

		scanf("%d", &n);
	}

	return 0;
}