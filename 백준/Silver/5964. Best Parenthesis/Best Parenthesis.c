#include<stdio.h>
#include<malloc.h>

#define MOD 12345678910

int main(void)
{
	int N, depth=1, data;
	long long *score=NULL;

	scanf("%d", &N);
	score=(long long *)malloc(N*sizeof(long long));

	for(int i=0;i<N;++i)
		score[i]=-1;

	while(N--)
	{
		scanf("%d", &data);

		if(data)
			if(score[--depth]!=-1)
			{
				if(score[depth-1]==-1)
					score[depth-1]=0;
				score[depth-1]=(score[depth-1]+(score[depth]<<1))%MOD;
				score[depth]=-1;
			}
			else
			{
				if(score[depth-1]==-1)
					score[depth-1]=0;
				score[depth-1]=(score[depth-1]+1)%MOD;
			}
		else
			score[depth++]=-1;
	}

	printf("%lld", score[0]%MOD);
	free(score);
	return 0;
}