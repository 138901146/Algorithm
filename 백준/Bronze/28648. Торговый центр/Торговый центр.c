#include<stdio.h>

int main(void)
{
	int n, t, l, min=999;

	scanf("%d", &n);

	while(n--)
	{
		scanf("%d%d", &t, &l);
		min=t+l<min?t+l:min;
	}

	printf("%d", min);
	return 0;
}