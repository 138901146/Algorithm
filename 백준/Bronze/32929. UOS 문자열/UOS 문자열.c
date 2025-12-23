#include<stdio.h>

int main(void)
{
	int x;

	scanf("%d", &x);

	printf("%c", x%3==1?'U':x%3==2?'O':'S');
	return 0;
}