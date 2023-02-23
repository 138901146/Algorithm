#include<stdio.h>

int main(void)
{
	int frequency[100]={0, }, average=0, number;

	for(int i=0;i<10;i++)
	{
		scanf("%d", &number);

		average+=number/10;
		frequency[number/10]++;
	}

	number=0;
	for(int i=1;i<100;i++)
		number=frequency[number]>frequency[i]?number:i;

	printf("%d\n%d\n", average, number*10);
	return 0;
}