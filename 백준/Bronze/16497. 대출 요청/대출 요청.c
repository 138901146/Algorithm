#include<stdio.h>

int main(void)
{
	int N, start, end, K, table[32]={0};

	scanf("%d", &N);

	while(N--)
	{
		scanf("%d%d", &start, &end);
		++table[start];
		--table[end];
	}

	scanf("%d", &K);

	for(int i=1;i<32;++i)
	{
		table[i]+=table[i-1];

		if(K<table[i])
		{
			printf("0");
			return 0;
		}
	}

	printf("1");
	return 0;
}