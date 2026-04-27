#include<stdio.h>

int main(void)
{
	int N, M;

	scanf("%d", &N);

	while(N--)
	{
		scanf("%d", &M);
		printf("%d ", M<250?4:M<275?3:M<300?2:1);
	}

	return 0;
}