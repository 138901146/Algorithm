#include<stdio.h>

int main(void)
{
	int n, sum=0;

	scanf("%d", &n);

	for(int i=1;i*i<=n;i++)
		if(n%i==0)
		{
			sum+=i;
			if(i*i!=n)
				sum+=n/i;
		}

	printf("%d\n", sum*5-24);

	return 0;
}