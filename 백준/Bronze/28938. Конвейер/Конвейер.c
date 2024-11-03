#include<stdio.h>

int main(void)
{
	int n, current=0, operation;

	scanf("%d", &n);

	while(n--)
	{
		scanf("%d", &operation);
		current+=operation;
	}

	printf("%s", current<0?"Left":0<current?"Right":"Stay");
	return 0;
}