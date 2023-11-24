#include<stdio.h>

int main(void)
{
	int t;

	scanf("%d", &t);

	while(t--)
	{
		int n, min=100, max=-1, x;

		scanf("%d", &n);

		while(n--)
		{
			scanf("%d", &x);
			min=x<min?x:min;
			max=x>max?x:max;
		}

		printf("%d\n", max-min<<1);
	}

	return 0;
}