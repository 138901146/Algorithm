#include<stdio.h>

int main(void)
{
	int N, min=1000000, max=-1000000;

	scanf("%d", &N);

	for(int i=0;i<N;i++)
	{
		int value;

		scanf("%d", &value);
		min=value<min?value:min;
		max=value>max?value:max;
	}
	printf("%d %d\n", min, max);

	return 0;
}