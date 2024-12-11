#include<stdio.h>

int main(void)
{
	int T, N, count[201]={0};

	scanf("%d", &T);

	for(int t=1;t<=T;++t)
	{
		scanf("%d", &N);

		if(count[N])
		{
			printf("#%d %d\n", t, count[N]);
			continue;
		}

		for(int i=0;i*i<=N*N;++i)
			for(int j=1;i*i+j*j<=N*N;++j,++count[N]);
		count[N]=count[N]<<2|1;

		printf("#%d %d\n", t, count[N]);
	}

	return 0;
}