#include<stdio.h>

int gcd(int x,int y)
{
	int temp;

	if(x<y)
	{
		temp=x;
		x=y;
		y=temp;
	}

	while(y)
	{
		temp=x%y;
		x=y;
		y=temp;
	}

	return x;
}

int main(void)
{
	int n, number, gcd_value, divisor[100]={1}, divisor_count=1, root;

	scanf("%d", &n);

	scanf("%d%d", &gcd_value, &number);

	gcd_value=gcd(gcd_value,number);

	if(n==3)
	{
		scanf("%d", &number);
		gcd_value=gcd(gcd_value,number);
	}

	if(gcd_value>1)
	{
		divisor[divisor_count++]=gcd_value;

		for(root=2;root*root<gcd_value;++root)
			if(gcd_value%root==0)
			{
				divisor[divisor_count++]=root;
				divisor[divisor_count++]=gcd_value/root;
			}

		if(root*root==gcd_value)
			divisor[divisor_count++]=root;
	}

	for(int i=1;i<divisor_count;++i)
		for(int j=i+1;j<divisor_count;++j)
			if(divisor[i]>divisor[j])
			{
				int temp=divisor[i];
				divisor[i]=divisor[j];
				divisor[j]=temp;
			}

	for(int i=0;i<divisor_count;++i)
		printf("%d\n", divisor[i]);
	return 0;
}