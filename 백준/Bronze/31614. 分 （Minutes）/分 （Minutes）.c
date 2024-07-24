#include<stdio.h>

int main(void)
{
	int H, M;

	scanf("%d", &H);
	scanf("%d", &M);

	printf("%d", 60*H+M);
	return 0;
}