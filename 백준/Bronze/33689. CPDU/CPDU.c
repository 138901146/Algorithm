#include<stdio.h>

int main(void)
{
	int N, count=0;

	scanf("%d", &N);

	while(N--)
	{
		char contest[21]={0};

		scanf("%s", contest);

		count+=contest[0]=='C';
	}

	printf("%d", count);
	return 0;
}