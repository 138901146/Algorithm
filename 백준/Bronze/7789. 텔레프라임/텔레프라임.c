#include<stdio.h>
#include<stdbool.h>

bool isPrime(int N)
{
	if(N<2)
		return false;
	else if(N==2)
		return true;
	else if(N%2==0)
		return false;
	else
		for(int n=3;n*n<=N;n+=2)
			if(N%n==0)
				return false;
	return true;
}

int main(void)
{
	int old, new;

	scanf("%d %d", &old, &new);

	new=1000000*new+old;

	printf("%s\n", isPrime(old)&&isPrime(new)?"Yes":"No");
	return 0;
}