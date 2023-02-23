#include<stdio.h>

int main(void)
{
	int n;

	scanf("%d", &n);

	switch(n%8)
	{
		case 1:
				printf("1\n");
				break;
		case 2:
		case 0:
				printf("2\n");
				break;
		case 3:
		case 7:
				printf("3\n");
				break;
		case 4:
		case 6:
				printf("4\n");
				break;
		case 5:
				printf("5\n");
				break;
	}
	return 0;
}