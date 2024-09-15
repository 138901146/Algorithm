#include<stdio.h>

int main(void)
{
	int N, score_A, score_B, win_A=0, win_B=0;

	scanf("%d", &N);

	while(N--)
	{
		scanf("%d%d", &score_A, &score_B);

		if(score_A>score_B)
			++win_A;
		else if(score_A<score_B)
			++win_B;
	}

	printf("%d %d", win_A, win_B);
	return 0;
}