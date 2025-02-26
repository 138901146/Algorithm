#include<stdio.h>

int main(void)
{
	int N;

	scanf("%d", &N);

	if(N<11)
	{
		printf("1");
		return 0;
	}

	for(int i=2;i<10;++i)
		if(N%i==0 && N/i<10)
		{
			printf("1");
			return 0;
		}

	printf("0");
	return 0;
}