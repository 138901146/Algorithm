#include<stdio.h>

int main(void)
{
	int N, count=0;

	scanf("%d", &N);

	while(N/10>0)
	{
		if((N%10)>4)
			N+=10;

		N/=10;
		count++;
	}

	for(int i=0;i<count;i++)
		N*=10;

	printf("%d\n", N);
	return 0;
}