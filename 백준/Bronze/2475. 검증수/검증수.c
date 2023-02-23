#include<stdio.h>

int main(void)
{
	int number[5], sum=0;

	for(int i=0;i<5;i++)
	{
		scanf("%d", &number[i]);

		sum+=number[i]*number[i];
	}

	printf("%d\n", sum%10);

	return 0;
}