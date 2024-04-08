#include<stdio.h>

int main(void)
{
	int score[2], T, F, S, P, C;

	for(int i=0;i<2;++i)
	{
		scanf("%d%d%d%d%d", &T, &F, &S, &P, &C);
		score[i]=6*T+3*F+(S+C<<1)+P;
	}

	printf("%d %d", score[0], score[1]);
	return 0;
}