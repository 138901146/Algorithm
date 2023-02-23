#include<stdio.h>

int main(void)
{
	int count=0, date;

	scanf("%d", &date);

	for(int i=0;i<5;i++)
	{
		int car;

		scanf("%d", &car);

		count+=date==car;
	}

	printf("%d\n", count);

	return 0;
}