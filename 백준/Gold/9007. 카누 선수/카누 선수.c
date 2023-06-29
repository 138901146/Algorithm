#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x>*(int *)y?1:*(int *)x==*(int *)y?0:-1;
}

int main(void)
{
	int T;

	scanf("%d", &T);

	for(int t=0;t<T;t++)
	{
		int k, n, **weight=NULL, **sum=NULL, diff=1000000000, left=0, right;

		scanf("%d%d", &k, &n);

		weight=(int **)malloc(4*sizeof(int *));
		sum=(int **)malloc(2*sizeof(int *));

		for(int i=0;i<4;i++)
		{
			weight[i]=(int *)malloc(n*sizeof(int));
			for(int j=0;j<n;j++)
				scanf("%d", &weight[i][j]);
		}

		for(int i=0;i<2;i++)
		{
			sum[i]=(int *)malloc(n*n*sizeof(int));
			for(int j=0;j<n;j++)
				for(int l=0;l<n;l++)
					sum[i][j*n+l]=weight[i<<1][j]+weight[i<<1|1][l];

			qsort((void *)sum[i],(size_t)n*n,sizeof(int),compare);

			for(int j=0;j<2;j++)
				free(weight[i<<1|j]);
		}
		free(weight);

		right=n*n-1;

		while(left<n*n && right>=0)
		{
			if(sum[0][left]+sum[1][right]==k)
			{
				diff=0;
				break;
			}
			else if(sum[0][left]+sum[1][right]<k)
			{
				if(k-sum[0][left]-sum[1][right]<=abs(diff))
					diff=sum[0][left]+sum[1][right]-k;
			}
			else
			{
				if(sum[0][left]+sum[1][right]-k<abs(diff))
					diff=sum[0][left]+sum[1][right]-k;
			}

			if(left==n*n-1)
				right--;
			else if(right==0)
				left++;
			else
			{
				if(sum[0][left]+sum[1][right]<k)
					left++;
				else
					right--;
			}
		}

		printf("%d\n", k+diff);
		for(int i=0;i<2;i++)
			free(sum[i]);
		free(sum);
	}

	return 0;
}