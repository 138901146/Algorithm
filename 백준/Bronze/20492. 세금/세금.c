#include<stdio.h>

int main(void)
{
	int N;

	scanf("%d", &N);

	printf("%d %d\n", (N/100)*78, (N/1000)*956);
	return 0;
}