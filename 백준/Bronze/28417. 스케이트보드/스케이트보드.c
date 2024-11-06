#include<stdio.h>

int main(void)
{
	int N, score[7], best=0;

	scanf("%d", &N);

	while(N--)
	{
		int sum=0, pri=0, sec=0, score;

		scanf("%d%d", &sum, &score);

		sum=sum<score?score:sum;

		for(int i=0;i<5;++i)
		{
			scanf("%d", &score);

			if(pri<=score)
			{
				sec=pri;
				pri=score;
			}
			else if(sec<score)
				sec=score;
		}

		sum+=pri+sec;

		best=sum<best?best:sum;
	}

	printf("%d", best);
	return 0;
}