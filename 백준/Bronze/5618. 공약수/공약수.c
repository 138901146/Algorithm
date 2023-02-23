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
	int n, num[3], gcd_num;

	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &num[i]);

	gcd_num=n==2?gcd(num[0],num[1]):gcd(gcd(num[0],num[1]),num[2]);

	for(int i=1;i<=gcd_num;i++)
		if(gcd_num%i==0)
			printf("%d\n", i);

	return 0;
}