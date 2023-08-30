#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, *stack=NULL, *continuous=NULL, top=0, height;
	long long count=0;

	scanf("%d", &N);
	stack=(int *)malloc(N*sizeof(int));
	continuous=(int *)malloc(N*sizeof(int));

	while(N--)
	{
		scanf("%d", &height);

		while(top>0 && stack[top-1]<height)
		{
			--top;
			++count;
		}

		if(top>0 && stack[top-1]==height)
		{
			count+=continuous[top-1];
			count+=top-continuous[top-1]>0;
		}
		else if(top>0)
			++count;

		continuous[top]=top>0 && stack[top-1]==height?continuous[top-1]+1:1;
		stack[top++]=height;
	}

	printf("%lld", count);
	free(stack);
	free(continuous);
	return 0;
}