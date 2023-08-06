#include<stdio.h>
#include<stdlib.h>

int *child_count=NULL, **child=NULL, *news=NULL;

int compare(const void *x,const void *y)
{
	return news[*(int *)x]>news[*(int *)y]?-1:1;
}

void get_news(int index)
{
	news[index]=0;

	for(int i=0;i<child_count[index];i++)
		get_news(child[index][i]);

	qsort((void *)child[index],(size_t)child_count[index],sizeof(int),compare);

	for(int i=0;i<child_count[index];i++)
		news[index]=news[child[index][i]]+i+1>news[index]?news[child[index][i]]+i+1:news[index];
}

int main(void)
{
	int N, *parent=NULL;

	scanf("%d", &N);
	parent=(int *)malloc(N*sizeof(int));
	child_count=(int *)calloc(N,sizeof(int));
	child=(int **)malloc(N*sizeof(int *));
	news=(int *)malloc(N*sizeof(int));

	scanf("%d", &parent[0]);
	for(int n=1;n<N;n++)
	{
		scanf("%d", &parent[n]);
		child_count[parent[n]]++;
	}

	for(int n=0;n<N;n++)
	{
		child[n]=(int *)malloc(child_count[n]*sizeof(int));
		child_count[n]=0;
	}

	for(int n=1;n<N;n++)
		child[parent[n]][child_count[parent[n]]++]=n;

	get_news(0);

	printf("%d\n", news[0]);
	for(int n=0;n<N;n++)
		free(child[n]);
	free(child);
	free(child_count);
	free(parent);
	free(news);
	return 0;
}