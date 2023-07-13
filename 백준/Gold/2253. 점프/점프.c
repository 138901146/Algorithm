#include<stdio.h>
#include<malloc.h>

int N, **stone=NULL;

int find_min(int number,int speed)
{
	if(number>N || number<=0 || speed<=0)
		return 20000000;
	if(number==N)
		return 0;
	if(stone[number][speed]<1000000)
		return stone[number][speed];
	if(stone[number][speed]==20000000)
		return 20000000;

	int next, min=10000000000;

	for(int i=-1;i<2;i++)
	{
		next=1+find_min(number+speed+i,speed+i);
		min=next<min?next:min;
	}

	return stone[number][speed]=min;
}

int main(void)
{
	int M, small;

	scanf("%d%d", &N, &M);
	stone=(int **)malloc((N+1)*sizeof(int *));

	for(int n=0;n<=N;n++)
	{
		stone[n]=(int *)malloc(143*sizeof(int));
		for(int i=0;i<143;i++)
			stone[n][i]=1000000;
	}

	for(int m=0;m<M;m++)
	{
		scanf("%d", &small);
		for(int i=0;i<143;i++)
			stone[small][i]=20000000;
	}

	small=find_min(2,1)+1;
	printf("%d\n", small>99999?-1:small);
	for(int n=0;n<N;n++)
		free(stone[n]);
	free(stone);
	return 0;
}