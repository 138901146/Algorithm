#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int H, C;
}
picture;

int compare(const void *x,const void *y)
{
	return ((picture *)x)->H<((picture *)y)->H?-1:((picture *)y)->H<((picture *)x)->H?1:((picture *)x)->C<((picture *)y)->C?-1:1;
}

int main(void)
{
	int N, S;
	long long *price=NULL, max=0;
	picture *displayed=NULL;

	scanf("%d%d", &N, &S);
	displayed=(picture *)calloc(N+1,sizeof(picture));
	price=(long long *)calloc(N+1,sizeof(long long));

	for(int i=0;i<N;++i)
		scanf("%d%d", &displayed[i].H, &displayed[i].C);
	qsort((void *)displayed,(size_t)N+1,sizeof(picture),compare);

	for(int i=1;i<=N;++i)
	{
		int left=0, right=i-1, fit=0;

		while(left<=right)
		{
			int mid=left+right>>1;

			if(displayed[i].H<displayed[mid].H+S)
				right=mid-1;
			else
			{
				left=mid+1;
				fit=mid;
			}
		}

		if(displayed[i].H<displayed[fit].H+S)
			price[i]=price[i-1];
		else
			price[i]=price[i-1]<price[fit]+displayed[i].C?price[fit]+displayed[i].C:price[i-1];
		max=price[i]<max?max:price[i];
	}

	printf("%lld", max);
	free(displayed);
	free(price);
	return 0;
}