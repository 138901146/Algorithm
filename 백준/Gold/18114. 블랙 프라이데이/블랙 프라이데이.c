#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x<*(int *)y?-1:1;
}

int main(void)
{
	int N, C, *w=NULL;

	scanf("%d%d", &N, &C);
	w=(int *)calloc(N+2,sizeof(int));

	for(int i=0;i<N;++i)
		scanf("%d", &w[i]);
	qsort((void *)w,(size_t)N+2,sizeof(int),compare);

	for(int i=0;i<N;++i)
		for(int j=i+1;j<N+1;++j)
		{
			int left=j+1, right=N+1, fit=left;

			while(left<=right)
			{
				int mid=left+right>>1, sum=w[i]+w[j]+w[mid];

				if(sum==C)
				{
					printf("1");
					free(w);
					return 0;
				}
				else if(sum<C)
				{
					left=mid+1;
					fit=mid;
				}
				else
					right=mid-1;
			}

			if(w[i]+w[j]+w[fit]==C)
			{
				printf("1");
				free(w);
				return 0;
			}
		}

	printf("0");
	free(w);
	return 0;
}