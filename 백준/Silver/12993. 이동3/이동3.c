#include<stdio.h>

int main(void)
{
	long long x, y, k;

	scanf("%lld%lld", &x, &y);

	if(x<y)
	{
		k=x;
		x=y;
		y=k;
	}

	k=1;
	while(k<=x)
		k*=3;
	k/=3;

	while(k)
	{
		if(x<y)
			y-=k;
		else
			x-=k;

		k/=3;
	}

	printf("%d", x==0&&y==0);
	return 0;
}