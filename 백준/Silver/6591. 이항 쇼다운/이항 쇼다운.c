#include<stdio.h>

int main(void)
{
	int n, k;

	scanf("%d %d", &n, &k);

	while(n!=0 || k!=0)
	{
		long double c=1.0;

		k=k>n-k?n-k:k;
		for(int i=0;i<k;i++)
			c*=(long double)(n-i)/(i+1);

		printf("%.0Lf\n", c);
		scanf("%d %d", &n, &k);
	}

	return 0;
}