#include<stdio.h>

int main(void)
{
	int N, y[5]={2024,2025,2025,2026,2026}, m[5]={8,3,10,5,12};

	scanf("%d", &N);

	printf("%d %d", y[N-1], m[N-1]);
	return 0;
}