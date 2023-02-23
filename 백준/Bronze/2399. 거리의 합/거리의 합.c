#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void)
{
	unsigned long long int n, *x=NULL, sum=0;

	scanf("%llu", &n);
	x=(unsigned long long int *)malloc(n*sizeof(unsigned long long int));

	for(int i=0;i<n;i++)
		scanf("%llu", &x[i]);

	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			sum+=2*abs(x[i]-x[j]);

	printf("%llu\n", sum);

	free(x);
	return 0;
}