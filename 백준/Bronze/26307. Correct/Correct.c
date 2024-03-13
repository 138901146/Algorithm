#include<stdio.h>

int main(void)
{
	int H, M;

	scanf("%d%d", &H, &M);

	printf("%d", 60*(H-9)+M);
	return 0;
}