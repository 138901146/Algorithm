#include<stdio.h>

int main(void)
{
	int N, h, stack[100001]={10000000, }, top=1;

	scanf("%d", &N);

	while(N--)
	{
		scanf("%d", &h);
		while(stack[top-1]<=h)
			top--;
		stack[top++]=h;
	}

	printf("%d\n", top-1);
	return 0;
}