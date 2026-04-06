#include<stdio.h>
#include<stdbool.h>

bool is_prime(int x)
{
	if(x<2)
		return false;
	else if(x==2)
		return true;
	else if(!(x&1))
		return false;
	else
		for(int i=3;i*i<=x;i+=2)
			if(!(x%i))
				return false;
	return true;
}

int main(void)
{
	int N, a;

	scanf("%d", &N);

	while(N--)
	{
		bool prime=false;

		scanf("%d", &a);

		for(int i=2;i*2<=a;++i)
			if(is_prime(i)&&is_prime(a-i))
			{
				prime=true;
				break;
			}

		printf("%s\n", prime?"Yes":"No");
	}

	return 0;
}