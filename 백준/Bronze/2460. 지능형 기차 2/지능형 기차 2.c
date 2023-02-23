#include<stdio.h>

int main(void)
{
	int current=0, max=0;

	for(int i=0;i<10;i++)
	{
		int on, off;

		scanf("%d %d", &off, &on);

		current+=(on-off);
		max=current>max?current:max;
	}

	printf("%d\n", max);

	return 0;
}