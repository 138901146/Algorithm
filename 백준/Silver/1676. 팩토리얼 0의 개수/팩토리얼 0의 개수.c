#include<stdio.h>

int divideby2(int N)
{
	int count=0;

	while(N%2==0)
	{
		count++;
		N/=2;
	}

	return count;
}

int divideby5(int N)
{
	int count=0;

	while(N%5==0)
	{
		count++;
		N/=5;
	}

	return count;
}

int main(void)
{
	int N, two=0, five=0;

	scanf("%d", &N);

	for(int i=2;i<=N;i++)
	{
		two+=divideby2(i);
		five+=divideby5(i);
	}

	printf("%d\n", two<five?two:five);

	return 0;
}