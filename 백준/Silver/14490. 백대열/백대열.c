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
	int n, m, gcd_nm;

	scanf("%d:%d", &n, &m);

	gcd_nm=gcd(n,m);
	n/=gcd_nm;
	m/=gcd_nm;

	printf("%d:%d\n", n, m);
	return 0;
}