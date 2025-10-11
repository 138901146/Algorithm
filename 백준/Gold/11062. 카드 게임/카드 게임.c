#include<stdio.h>
#include<memory.h>

int card[1001], score[1001][1001][2][2], sum[1001];

int simulate(int left,int right,int turn)
{
	if(score[left][right][turn][turn]||score[left][right][turn][turn^1])
		return score[left][right][turn][turn];
	else if(left==right)
		return score[left][right][turn][turn]=card[left];
	else if(right<left)
		return 0;

	int left_score, right_score;

	simulate(left+1,right,turn^1);
	simulate(left,right-1,turn^1);
	left_score=card[left]+score[left+1][right][turn^1][turn];
	right_score=card[right]+score[left][right-1][turn^1][turn];

	score[left][right][turn][turn]=left_score<right_score?right_score:left_score;
	score[left][right][turn][turn^1]=sum[right]-sum[left-1]-score[left][right][turn][turn];

	return score[left][right][turn][turn];
}

int main(void)
{
	int T, N;

	scanf("%d", &T);

	while(T--)
	{
		memset(sum,0,1001*sizeof(int));
		memset(score,0,4008004*sizeof(int));

		scanf("%d", &N);
		for(int i=1;i<=N;++i)
		{
			scanf("%d", &card[i]);
			sum[i]=sum[i-1]+card[i];
		}

		printf("%d\n", simulate(1,N,0));
	}

	return 0;
}