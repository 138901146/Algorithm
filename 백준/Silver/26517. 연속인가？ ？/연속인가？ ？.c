#include<stdio.h>

int main(void)
{
	long long k, a, b, c, d;

	scanf("%lld", &k);
	scanf("%lld%lld%lld%lld", &a, &b, &c, &d);

	if(a*k+b==c*k+d)
		printf("Yes %lld", a*k+b);
	else
		printf("No");
	return 0;
}