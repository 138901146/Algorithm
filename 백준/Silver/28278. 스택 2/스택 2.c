#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, *stack=NULL, top=0, operation, X;

	scanf("%d", &N);
	stack=(int *)malloc(N*sizeof(int));

	while(N--)
	{
		scanf("%d", &operation);

		switch(operation)
		{
			case 1:
				scanf("%d", &X);
				stack[top++]=X;
				break;
			case 2:
				printf("%d\n", top>0?stack[--top]:-1);
				break;
			case 3:
				printf("%d\n", top);
				break;
			case 4:
				printf("%d\n", top==0);
				break;
			case 5:
				printf("%d\n", top>0?stack[top-1]:-1);
				break;
		}
	}

	free(stack);
	return 0;
}