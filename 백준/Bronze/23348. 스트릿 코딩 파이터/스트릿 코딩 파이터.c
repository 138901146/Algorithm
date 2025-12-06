#include<stdio.h>

int main(void)
{
	int N, A, B, C, a, b, c, score, max=0;

	scanf("%d%d%d", &A, &B, &C);
	scanf("%d", &N);

	while(N--)
	{
		int score=0;

		for(int i=0;i<3;++i)
		{
			scanf("%d%d%d", &a, &b, &c);
			score+=A*a+B*b+C*c;
		}
		max=score<max?max:score;
	}

	printf("%d", max);
	return 0;
}