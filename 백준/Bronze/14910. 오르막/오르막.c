#include<stdio.h>

int main(void)
{
	int num, last=-1000000;

	while(scanf("%d", &num)!=EOF)
	{
		if(num<last)
		{
			printf("Bad");
			return 0;
		}

		last=num;
	}

	printf("Good");
	return 0;
}