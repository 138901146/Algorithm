#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int w, h;
}
rectangle;

int compare(const void *x,const void *y)
{
	return ((rectangle *)x)->w<((rectangle *)y)->w?1:((rectangle *)y)->w<((rectangle *)x)->w?-1:((rectangle *)x)->h<((rectangle *)y)->h?1:-1;
}

int main(void)
{
	int N, count[100], max=0;
	rectangle paper[100];

	scanf("%d", &N);

	for(int i=0;i<N;++i)
	{
		scanf("%d%d", &paper[i].w, &paper[i].h);

		if(paper[i].w<paper[i].h)
		{
			int temp=paper[i].w;
			paper[i].w=paper[i].h;
			paper[i].h=temp;
		}
	}

	qsort((void *)paper,(size_t)N,sizeof(rectangle),compare);

	for(int i=0;i<N;++i)
	{
		count[i]=1;

		for(int j=0;j<i;++j)
			if(paper[i].w<=paper[j].w&&paper[i].h<=paper[j].h)
				count[i]=count[j]+1<count[i]?count[i]:count[j]+1;

		max=count[i]<max?max:count[i];
	}

	printf("%d", max);
	return 0;
}