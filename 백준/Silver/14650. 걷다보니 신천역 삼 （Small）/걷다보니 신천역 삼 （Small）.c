#include<stdio.h>

int N, count=0;

void simulate(int current,long long number)
{
	if(current==N)
	{
		if(!(number%3))
			++count;
		return;
	}

	if(current)
		simulate(current+1,number*10);
	simulate(current+1,number*10+1);
	simulate(current+1,number*10+2);
}

int main(void)
{
	scanf("%d", &N);

	simulate(0,0);

	printf("%d", count);
	return 0;
}