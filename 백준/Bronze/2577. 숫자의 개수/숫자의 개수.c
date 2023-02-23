#include<stdio.h>

int main(void)
{
	int temp, mul=1, frequency[10]={0, };

	for(int i=0;i<3;i++)
	{
		scanf("%d", &temp);
		mul*=temp;
	}

	while(mul>0)
	{
		frequency[mul%10]++;
		mul/=10;
	}

	for(int i=0;i<10;i++)
		printf("%d\n", frequency[i]);

	return 0;
}