#include<stdio.h>
#include<stdbool.h>

int min=1;
bool prime[8]={false,false,true,true,false,true,false,true};

bool is_prime(int n)
{
	if(n<2)
		return false;
	else if(n==2)
		return true;
	else if(n%2==0)
		return false;
	else
		for(int i=3;i*i<=n;i+=2)
			if(n%i==0)
				return false;
	return true;
}

void amazing_prime(int num)
{
	if(num>min)
	{
		printf("%d\n", num);
		return;
	}

	if(num==0)
	{
		for(int i=2;i<8;i++)
			if(prime[i])
				amazing_prime(i);
		return;
	}

	for(int i=1;i<10;i+=2)
		if(is_prime(10*num+i))
			amazing_prime(10*num+i);
}

int main(void)
{
	int N;

	scanf("%d", &N);
	for(int n=1;n<N;n++)
		min*=10;

	amazing_prime(0);

	return 0;
}