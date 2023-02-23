#include<stdio.h>

int main(void)
{
	int N, count=0, table[9]={1,10,100,1000,10000,100000,1000000,10000000,100000000};

	scanf("%d", &N);

	for(int n=1;n<=N;n++)
		for(int i=8;i>=0;i--)
			if(n>=table[i])
			{
				count+=i+1;
				break;
			}

	printf("%d\n", count);
	return 0;
}