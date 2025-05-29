#include<stdio.h>

int main(void)
{
	int T, N, min[10001]={0}, last=0;

	scanf("%d", &T);

	for(int i=1;i<101;++i)
		min[i*i]=1;

	for(int x=1;x<=T;++x)
	{
		scanf("%d", &N);

		if(min[N])
		{
			printf("Case #%d: %d\n", x, min[N]);
			continue;
		}

		for(int i=last+1;i<=N;++i)
			if(!min[i])
			{
				min[i]=i;
				for(int j=1;j<i;++j)
					min[i]=min[j]+min[i-j]<min[i]?min[j]+min[i-j]:min[i];
			}
		last=N;

		printf("Case #%d: %d\n", x, min[N]);
	}

	return 0;
}