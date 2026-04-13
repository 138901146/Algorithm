#include<stdio.h>

int is_prime(int x)
{
	if(x<2)
		return 0;
	else if(x==2)
		return 1;
	else if(!(x&1))
		return 0;
	for(int i=3;i*i<=x;i+=2)
		if(!(x%i))
			return 0;
	return 1;
}

int main(void)
{
	int N, count=0;

	scanf("%d", &N);

	for(int i=3;count<N;i+=2)
		if(is_prime(i))
		{
			printf("%d ", i);
			++count;
		}

	return 0;
}