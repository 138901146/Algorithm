#include<stdio.h>

int main(void)
{
	int N, power[2000], max[2000]={0}, best=0;

	scanf("%d", &N);
	for(int n=0;n<N;++n)
		scanf("%d", &power[n]);

	for(int current=0;current<N;++current)
	{
		for(int previous=0;previous<current;++previous)
			if(power[current]<power[previous])
				max[current]=max[previous]<max[current]?max[current]:max[previous];
		++max[current];
		best=max[current]<best?best:max[current];
	}

	printf("%d", N-best);
	return 0;
}