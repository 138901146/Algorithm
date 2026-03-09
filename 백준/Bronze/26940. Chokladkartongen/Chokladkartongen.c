#include<stdio.h>

int main(void)
{
	int N, chocolate[2]={0}, current=0, previous=1, count=0;

	scanf("%d", &N);

	scanf("%d", &chocolate[1]);

	while(--N)
	{
		scanf("%d", &chocolate[current]);

		if(chocolate[previous]<chocolate[current])
			++count;

		current^=1;
		previous^=1;
	}

	printf("%d", count);
	return 0;
}