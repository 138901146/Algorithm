#include<stdio.h>

int main(void)
{
	int N;

	scanf("%d", &N);

	printf("%s", 100000<N||N%2024?"No":"Yes");
	return 0;
}