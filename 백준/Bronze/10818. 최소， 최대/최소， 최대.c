#include<stdio.h>

int main(void)
{
	int N, value, min=1000000, max=-1000000;

	scanf("%d", &N);

	while(N--)
	{
		scanf("%d", &value);
		min=value<min?value:min;
		max=value>max?value:max;
	}

	printf("%d %d", min, max);
	return 0;
}