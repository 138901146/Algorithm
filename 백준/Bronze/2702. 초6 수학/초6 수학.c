#include<stdio.h>

int gcd(int x,int y)
{
	if(x<y)
	{
		int temp=x;
		x=y;
		y=temp;
	}

	while(y!=0)
	{
		int temp=x%y;
		x=y;
		y=temp;
	}

	return x;
}

int main(void)
{
	int T, a, b, gcd_ab;

	scanf("%d", &T);

	for(int t=0;t<T;t++)
	{
		scanf("%d %d", &a, &b);

		gcd_ab=gcd(a,b);
		printf("%d %d\n", a*b/gcd_ab, gcd_ab);
	}

	return 0;
}