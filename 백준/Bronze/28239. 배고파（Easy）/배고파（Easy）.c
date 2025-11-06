#include<stdio.h>

int main(void)
{
	int n;

	scanf("%d", &n);

	while(n--)
	{
		long long m;
		int x=-1, y=-1;

		scanf("%lld", &m);

		for(int i=0;i<64;++i)
			if(((long long)1<<i)&m)
			{
				if(x==-1)
					x=i;
				else
					y=i;
			}

		if(y==-1)
			x=y=x-1;
		if(y<x)
		{
			int temp=x;
			x=y;
			y=temp;
		}

		printf("%d %d\n", x, y);
	}

	return 0;
}