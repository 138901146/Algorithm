#include<stdio.h>

int main(void)
{
	int n;

	scanf("%d", &n);

	switch(n)
	{
		case 0:
			printf("1");
			break;
		case 1:
		case 2:
		case 4:
			printf("%d", n);
			break;
		case 3:
			printf("6");
			break;
		default:
			printf("0");
			break;
	}

	return 0;
}