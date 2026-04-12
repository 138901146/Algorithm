#include<stdio.h>

int main(void)
{
	int N, M, max[101][2]={1,0}, a[101], current=0, next=1, best=1;

	scanf("%d%d", &N, &M);
	for(int i=1;i<=N;++i)
		scanf("%d", &a[i]);

	while(M--)
	{
		for(int i=0;i<N;++i)
			if(max[i][current])
			{
				max[i+1][next]=max[i+1][next]<max[i][current]+a[i+1]?max[i][current]+a[i+1]:max[i+1][next];
				max[i+2][next]=max[i+2][next]<max[i][current]/2+a[i+2]?max[i][current]/2+a[i+2]:max[i+2][next];
			}

		for(int i=0;i<=N;++i)
		{
			max[i][current]=0;
			best=best<max[i][next]?max[i][next]:best;
		}

		current^=1;
		next^=1;
	}

	printf("%d", best);
	return 0;
}