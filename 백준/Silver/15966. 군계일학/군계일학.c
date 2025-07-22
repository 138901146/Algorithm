#include<stdio.h>

int max_length[1000001]={0};

int main(void)
{
	int N, a, max=0;

	scanf("%d", &N);

	while(N--)
	{
		scanf("%d", &a);

		max_length[a]=max_length[a-1]+1<max_length[a]?max_length[a]:max_length[a-1]+1;
		max=max_length[a]<max?max:max_length[a];
	}

	printf("%d", max);
	return 0;
}