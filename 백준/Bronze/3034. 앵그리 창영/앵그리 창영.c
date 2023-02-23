#include<stdio.h>

int main(void)
{
	int N, W, H, square;

	scanf("%d %d %d", &N, &W, &H);
	square=W*W+H*H;

	for(int n=0;n<N;n++)
	{
		int length;

		scanf("%d", &length);
		printf("%s\n", length*length<=square?"DA":"NE");
	}

	return 0;
}