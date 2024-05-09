#include<stdio.h>

int N, K, C[10][10], max=-10000000;

void simulate(int current,int count,int sum,int G)
{
	if(count==K)
	{
		max=max<sum?sum:max;
		return;
	}

	if(current==N)
		return;

	int plus=0;

	for(int i=0;i<current;++i)
		if(G&(1<<i))
			plus+=C[i][current];

	simulate(current+1,count+1,sum+plus,1<<current|G);
	simulate(current+1,count,sum,G);
}

int main(void)
{
	scanf("%d%d", &N, &K);

	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
			scanf("%d", &C[i][j]);

	simulate(0,0,0,0);

	printf("%d", max);
	return 0;
}