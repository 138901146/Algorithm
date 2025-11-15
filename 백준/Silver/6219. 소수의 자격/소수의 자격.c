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
			if(x%i==0)
				return false;
	return true;
}

int main(void)
{
	int A, B, D, count=0;

	scanf("%d%d%d", &A, &B, &D);

	for(int i=A;i<=B;++i)
	{
		int temp=i;

		while(temp)
		{
			if(temp%10==D)
			{
				count+=is_prime(i);
				break;
			}
			temp/=10;
		}
	}

	printf("%d", count);
	return 0;
}