#include<stdio.h>
#include<math.h>

int main(void)
{
	unsigned long long int n, q;

	scanf("%llu", &n);

	q=(unsigned long long int)sqrt(n);
	if(q*q<n)
		q++;

	printf("%llu\n", q);
	return 0;
}