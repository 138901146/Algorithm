#include<stdio.h>

int main(void)
{
	int N, K, max=0;

	scanf("%d%d", &N, &K);

	for(int k=1;k<=K;++k)
	{
		int reverse=0, temp=N*k;

		while(temp)
		{
			reverse=reverse*10+temp%10;
			temp/=10;
		}

		max=reverse<max?max:reverse;
	}

	printf("%d", max);
	return 0;
}