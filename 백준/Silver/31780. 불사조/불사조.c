#include<stdio.h>

int power[2][1048576]={0};

int main(void)
{
	int X, M, current=0, next=1, count[2]={0};
	long long total;

	scanf("%d%d", &X, &M);

	total=power[0][0]=X;
	count[0]=1;

	while(M--)
	{
		count[next]=0;

		for(int i=0;i<count[current];++i)
		{
			X=power[current][i];

			if(X>>1)
			{
				power[next][count[next]]=X>>1;
				total+=power[next][count[next]++];
			}
			if(X-(X>>1))
			{
				power[next][count[next]]=X-(X>>1);
				total+=power[next][count[next]++];
			}
		}

		current^=1;
		next^=1;
	}

	printf("%lld", total);
	return 0;
}