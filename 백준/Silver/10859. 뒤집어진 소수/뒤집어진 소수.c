#include<stdio.h>
#include<stdbool.h>

bool is_prime(long long x)
{
	if(x<2)
		return false;
	else if(x==2)
		return true;
	else if(x%2==0)
		return false;
	for(long long i=3;i*i<=x;i+=2)
		if(x%i==0)
			return false;
	return true;
}

int main(void)
{
	long long original, reverse=0;
	bool able=true;

	scanf("%lld", &original);

	if(!is_prime(original))
		able=false;
	else
		while(original>0)
		{
			switch(original%10)
			{
				case 0:
				case 2:
				case 5:
				case 8:
				case 1:
					break;
				case 6:
					original+=3;
					break;
				case 9:
					original-=3;
					break;
				default:
					able=false;
					break;
			}

			if(!able)
				break;

			reverse*=10;
			reverse+=original%10;
			original/=10;
		}

	if(able&&is_prime(reverse))
		printf("yes\n");
	else
		printf("no\n");
	return 0;
}