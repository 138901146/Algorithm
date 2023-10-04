#include<stdio.h>

int main(void)
{
	int n, d, count=0;

	scanf("%d%d", &n, &d);

	for(int i=1;i<=n;++i)
	{
		int temp=i;

		while(temp)
		{
			count+=temp%10==d;
			temp/=10;
		}
	}

	printf("%d", count);
	return 0;
}