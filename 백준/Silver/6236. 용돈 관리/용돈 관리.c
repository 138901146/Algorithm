#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, M, left=1, right=1000000000, K=1, *pocket_money=NULL, max=0;

	scanf("%d%d", &N, &M);
	pocket_money=(int *)malloc(N*sizeof(int));

	for(int n=0;n<N;++n)
	{
		scanf("%d", &pocket_money[n]);
		max=max<pocket_money[n]?pocket_money[n]:max;
	}

	while(left<=right)
	{
		int mid=left+right>>1, count=0, current=0;

		for(int n=0;n<N;++n)
			if(pocket_money[n]<=current)
				current-=pocket_money[n];
			else if(pocket_money[n]%mid)
			{
				current=mid-pocket_money[n]%mid;
				count+=pocket_money[n]/mid+1;
			}
			else
			{
				current=0;
				count+=pocket_money[n]/mid;
			}

		if(count<=M)
		{
			K=mid;
			right=mid-1;
		}
		else
			left=mid+1;
	}

	printf("%d", K<max?max:K);
	free(pocket_money);
	return 0;
}