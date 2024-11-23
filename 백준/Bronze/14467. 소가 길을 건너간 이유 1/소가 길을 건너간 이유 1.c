#include<stdio.h>

int main(void)
{
	int N, cow, move, recent[11], count=0;

	for(int i=1;i<11;++i)
		recent[i]=-1;

	scanf("%d", &N);

	while(N--)
	{
		scanf("%d%d", &cow, &move);

		if(recent[cow]==-1)
			recent[cow]=move;
		else if(recent[cow]!=move)
		{
			++count;
			recent[cow]=move;
		}
	}

	printf("%d", count);
	return 0;
}