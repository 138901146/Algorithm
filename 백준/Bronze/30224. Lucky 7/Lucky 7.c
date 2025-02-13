#include<stdio.h>

int main(void)
{
	int number, divisible, contain=0;

	scanf("%d", &number);

	divisible=!(number%7);
	while(number)
	{
		if(number%10==7)
			contain=1;
		number/=10;
	}

	printf("%d", contain<<1|divisible);
	return 0;
}