#include<stdio.h>
#include<malloc.h>

#define INF 1000000001

int abs(int x)
{
	return x<0?-x:x;
}

int main(void)
{
	int N, *liquid=NULL, left=0, right, best_sum=INF<<1, best[2];

	scanf("%d", &N);
	liquid=(int *)malloc(N*sizeof(int));

	for(int n=0;n<N;++n)
		scanf("%d", &liquid[n]);

	right=N-1;
	while(left<right)
	{
		int sum=liquid[left]+liquid[right];

		if(!sum)
		{
			printf("%d %d", liquid[left], liquid[right]);
			free(liquid);
			return 0;
		}
		else if(sum<0)
		{
			if(-sum<abs(best_sum))
			{
				best_sum=sum;
				best[0]=liquid[left];
				best[1]=liquid[right];
			}

			++left;
		}
		else
		{
			if(sum<abs(best_sum))
			{
				best_sum=sum;
				best[0]=liquid[left];
				best[1]=liquid[right];
			}

			--right;
		}
	}

	printf("%d %d", best[0], best[1]);
	free(liquid);
	return 0;
}