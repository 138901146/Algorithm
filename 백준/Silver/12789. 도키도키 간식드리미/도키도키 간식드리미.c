#include<stdio.h>

int main(void)
{
	int N, order, stack[1000], top=0, done=1;

	scanf("%d", &N);

	while(N--)
	{
		scanf("%d", &order);

		while(top && stack[top-1]==done)
		{
			--top;
			++done;
		}

		if(order==done)
		{
			++done;
			continue;
		}

		if(top && stack[top-1]<order)
		{
			printf("Sad");
			return 0;
		}
		stack[top++]=order;
	}

	printf("Nice");
	return 0;
}