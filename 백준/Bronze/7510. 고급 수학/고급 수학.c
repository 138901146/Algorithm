#include<stdio.h>

int main(void)
{
	int n, a, b, c;

	scanf("%d", &n);

	for(int i=1;i<=n;i++)
	{
		scanf("%d %d %d", &a, &b, &c);

		if(a>b)
		{
			int d=a;
			a=b;
			b=d;
		}
		if(a>c)
		{
			int d=a;
			a=c;
			c=d;
		}
		if(b>c)
		{
			int d=b;
			b=c;
			c=d;
		}

		printf("Scenario #%d:\n%s\n\n", i, a*a+b*b==c*c?"yes":"no");
	}

	return 0;
}