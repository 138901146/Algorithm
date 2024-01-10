#include<stdio.h>

int N, K, X[50], Y[50], min=1000000000, selected[3];

int abs(int x)
{
	return x>0?x:-x;
}

void calculate_distance(void)
{
	int max=0;

	for(int n=0;n<N;++n)
	{
		int distance=1000000000;

		for(int k=0;k<K;++k)
			if(abs(X[n]-X[selected[k]])+abs(Y[n]-Y[selected[k]])<distance)
				distance=abs(X[n]-X[selected[k]])+abs(Y[n]-Y[selected[k]]);

		max=distance>max?distance:max;
	}

	min=max<min?max:min;
}

void combination(int current,int depth)
{
	if(depth==K)
	{
		calculate_distance();
		return;
	}

	for(int i=current;i<N;++i)
	{
		selected[depth]=i;
		combination(i+1,depth+1);
	}
}

int main(void)
{
	scanf("%d%d", &N, &K);

	for(int i=0;i<N;++i)
		scanf("%d%d", &X[i], &Y[i]);

	combination(0,0);

	printf("%d", min);
	return 0;
}