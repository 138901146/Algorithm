#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, M, L, *ball=NULL, state=0, count=0;

	scanf("%d %d %d", &N, &M, &L);
	ball=(int *)calloc(N,sizeof(int));

	ball[0]=1;
	while(ball[state]<M)
	{
		count++;

		state+=ball[state]%2==0?-L:L;
		if(state<0)
			state+=N;
		else if(state>=N)
			state-=N;

		ball[state]++;
	}

	printf("%d\n", count);
	free(ball);
	return 0;
}