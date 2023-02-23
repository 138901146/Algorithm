#include<stdio.h>

int main(void)
{
	float cheap;
	int N, X, Y;

	scanf("%d %d", &X, &Y);
	cheap=X*(1000.0/Y);
	scanf("%d", &N);

	for(int n=0;n<N;n++)
	{
		scanf("%d %d", &X, &Y);
		cheap=X*(1000.0/Y)<cheap?X*(1000.0/Y):cheap;
	}

	printf("%.2f\n", cheap);
	return 0;
}