#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int T, N, *stock=NULL, *stack=NULL, top, count;
	long long sum;

	scanf("%d", &T);
	for(int t=0;t<T;t++)
	{
		count=sum=top=0;
		scanf("%d", &N);

		stock=(int *)malloc(N*sizeof(int));
		stack=(int *)malloc(N*sizeof(int));

		for(int n=0;n<N;n++)
			scanf("%d", &stock[n]);

		stack[top++]=N-1;
		for(int n=N-2;n>=0;n--)
			if(stock[n]>=stock[stack[top-1]])
				stack[top++]=n;

		for(int n=0;n<N;n++)
			if(stack[top-1]==n)
			{
				sum+=count*stock[n];
				count=0;
				top--;
			}
			else if(stock[n]<stock[stack[top-1]])
			{
				count++;
				sum-=stock[n];
			}

		printf("%lld\n", sum);
		free(stock);
		free(stack);
	}

	return 0;
}