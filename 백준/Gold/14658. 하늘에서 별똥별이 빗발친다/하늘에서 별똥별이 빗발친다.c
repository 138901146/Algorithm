#include<stdio.h>

int main(void)
{
	int N, M, L, K, x[100], y[100], max=0;

	scanf("%d%d%d%d", &N, &M, &L, &K);

	for(int i=0;i<K;++i)
		scanf("%d%d", &x[i], &y[i]);

	for(int i=0;i<K;++i)
		for(int j=0;j<K;++j)
		{
			int count=0;

			for(int k=0;k<K;++k)
				count+=x[i]<=x[k] && x[k]<=x[i]+L && y[j]<=y[k] && y[k]<=y[j]+L;

			max=count<max?max:count;
		}

	printf("%d", K-max);
	return 0;
}