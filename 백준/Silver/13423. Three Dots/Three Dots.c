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
		int N, *X=NULL, count=0;

		scanf("%d", &N);
		X=(int *)malloc(N*sizeof(int));

		for(int n=0;n<N;n++)
			scanf("%d", &X[n]);

		qsort((void *)X,(size_t)N,sizeof(int),compare);

		for(int i=0;i<N-2;i++)
			for(int j=i+2;j<N;j++)
			{
				int left=i+1, right=j-1, mid=(left+right)>>1;

				while(left<=right)
				{
					if((X[mid]<<1)==X[i]+X[j])
						break;
					else if((X[mid]<<1)<X[i]+X[j])
						left=mid+1;
					else
						right=mid-1;

					mid=(left+right)>>1;
				}

				mid=(left+right)>>1;
				if(i!=mid && j!=mid && (X[mid]<<1)==X[i]+X[j])
					count++;
			}

		printf("%d\n", count);
		free(X);
	}

	return 0;
}