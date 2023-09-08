#include<stdio.h>
int deque[2000001];

int main(void)
{
	int N, operation, X, front=1000000, rear=1000000;

	scanf("%d", &N);

	while(N--)
	{
		scanf("%d", &operation);

		switch(operation)
		{
			case 1:
				scanf("%d", &X);
	 			deque[--front]=X;
				break;
			case 2:
				scanf("%d", &X);
				deque[rear++]=X;
				break;
			case 3:
				printf("%d\n", front==rear?-1:deque[front++]);
				break;
			case 4:
				printf("%d\n", front==rear?-1:deque[--rear]);
				break;
			case 5:
				printf("%d\n", rear-front);
				break;
			case 6:
				printf("%d\n", front==rear);
				break;
			case 7:
				printf("%d\n", front==rear?-1:deque[front]);
				break;
			case 8:
				printf("%d\n", front==rear?-1:deque[rear-1]);
				break;
		}
	}

	return 0;
}