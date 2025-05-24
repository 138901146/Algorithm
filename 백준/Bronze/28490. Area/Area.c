#include<stdio.h>

int main(void)
{
	int n, w, h, max=0;

	scanf("%d", &n);

	while(n--)
	{
		scanf("%d%d", &h, &w);
		max=h*w<max?max:h*w;
	}

	printf("%d", max);
	return 0;
}