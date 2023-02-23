#include<stdio.h>

int main(void)
{
	int n;

	scanf("%d", &n);

	if(n==1 || n==3)
		printf("-1\n");
	else
	{
		switch(n%10)
		{
			case 0:
			case 5:
				printf("%d\n", n/5);
				break;
			case 1:
			case 3:
				printf("%d\n", (n-10-(n%10))/5+4+(n%10)/2);
				break;
			case 2:
			case 4:
				printf("%d\n", n/5+(n%10)/2);
				break;
			case 6:
			case 8:
				printf("%d\n", (n-(n%10))/5+(n%10)/2);
				break;
			case 7:
			case 9:
				printf("%d\n", n/5+((n-5)%10)/2);
				break;
		}
	}

	return 0;
}