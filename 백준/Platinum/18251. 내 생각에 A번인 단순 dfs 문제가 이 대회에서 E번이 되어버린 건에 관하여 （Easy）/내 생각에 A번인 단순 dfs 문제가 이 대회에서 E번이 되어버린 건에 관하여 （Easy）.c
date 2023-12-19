#include<stdio.h>
#include<malloc.h>

typedef struct
{
	int index, depth, value;
}
tree_info;

int main(void)
{
	int N, *W=NULL, total_depth=0;
	tree_info *map=NULL;
	long long answer;

	scanf("%d", &N);
	W=(int *)malloc((N+1)*sizeof(int));
	map=(tree_info *)malloc((N+1)*sizeof(tree_info));
	while((1<<total_depth)<N)
		++total_depth;

	for(int n=1;n<=N;++n)
		scanf("%d", &W[n]);
	answer=W[1];

	for(int n=0;(1<<n)<N;++n)
	{
		int start=(N>>n+1)+1;
		for(int i=(1<<n)-1;i<=N;i+=(1<<n+1))
		{
			map[i+1].index=start;
			map[i+1].depth=total_depth-n;
			map[i+1].value=W[start++];
		}
	}

	for(int low=1;low<=total_depth;++low)
		for(int high=low;high<=total_depth;++high)
		{
			int start=1<<(total_depth-high), end=N+1-start;
			long long max=-10000000000, sum=0;

			for(int i=start;i<=end;++i)
				if(low<=map[i].depth && map[i].depth<=high)
				{
					sum=sum+map[i].value<map[i].value?map[i].value:sum+map[i].value;
					max=max<sum?sum:max;
				}

			answer=max<answer?answer:max;
		}

	printf("%lld", answer);
	free(map);
	free(W);
	return 0;
}