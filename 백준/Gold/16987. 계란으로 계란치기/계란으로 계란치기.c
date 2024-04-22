#include<stdio.h>

int N, W[8], max=0;

void simulate(int left,int *S)
{
	if(left==N)
	{
		int broken=0;

		for(int i=0;i<N;++i)
			broken+=S[i]<=0;

		max=max<broken?broken:max;
		return;
	}

	int breakable=0;

	for(int i=0;i<N;++i)
		if(i!=left && 0<S[left] && 0<S[i])
		{
			S[i]-=W[left];
			S[left]-=W[i];
			simulate(left+1,S);
			S[i]+=W[left];
			S[left]+=W[i];
			breakable=1;
		}

	if(!breakable)
		simulate(left+1,S);
}

int main(void)
{
	int S[8];

	scanf("%d", &N);

	for(int i=0;i<N;++i)
		scanf("%d%d", &S[i], &W[i]);

	simulate(0,S);

	printf("%d", max);
	return 0;
}