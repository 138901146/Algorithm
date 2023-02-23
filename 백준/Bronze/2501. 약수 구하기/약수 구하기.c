#include<stdio.h>

int main(void)
{
	int count=0, N, K;

	scanf("%d %d", &N, &K);

	for(int i=1;i<=N;i++)
	{
		count+=N%i==0;
		if(count==K)
		{
			printf("%d", i);
			break;
		}
	}

	if(count<K)
		printf("0");

	return 0;
}