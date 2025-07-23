#include<stdio.h>

int main(void)
{
	int N;

	scanf("%d", &N);

	while(N)
	{
		long long max=-99999, P[2]={0,0}, current=0, previous=1;

		while(N--)
		{
			scanf("%lld", &P[current]);

			
			if(0<P[previous])
				P[current]+=P[previous];
			max=P[current]<max?max:P[current];

			current^=1;
			previous^=1;
		}

		printf("%lld\n", max);
		scanf("%d", &N);
	}

	return 0;
}