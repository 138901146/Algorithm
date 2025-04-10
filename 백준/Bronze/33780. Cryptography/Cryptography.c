#include<stdio.h>
#include<stdbool.h>

bool is_prime(long long x)
{
	if(x<2)
		return false;
	else if(x==2)
		return true;
	else if(!(x&1))
		return false;
	for(long long i=3;i*i<=x;++i)
		if(!(x%i))
			return false;
	return true;
}

int main(void)
{
	long long n;

	scanf("%lld", &n);

	printf("%s", is_prime(n)?"SAFE":"BROKEN");
	return 0;
}