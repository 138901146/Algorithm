#include<stdio.h>

int main(void)
{
	int n, v, max=0, sum=0;

	scanf("%d", &n);

	while(n--)
	{
		scanf("%d", &v);
		sum+=v;
		max=v<max?max:v;
	}

	printf("%d", sum-max);
	return 0;
}