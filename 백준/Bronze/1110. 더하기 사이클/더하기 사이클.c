#include<stdio.h>

int main(void)
{
	int N, temp, count=0;

	scanf("%d", &N);

	temp=N;
	do
	{
		temp=10*(temp%10)+(temp/10+temp%10)%10;
		count++;
	}
	while(temp!=N);

	printf("%d\n", count);

	return 0;
}