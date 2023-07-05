#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int x, y;
}
coordinate;

int compare(const void *x,const void *y)
{
	return (((coordinate *)x)->x>((coordinate *)y)->x || ((coordinate *)x)->x==((coordinate *)y)->x && ((coordinate *)x)->y>((coordinate *)y)->y)?1:-1;
}

int main(void)
{
	int N, A, B, count=0;
	coordinate *list=NULL;

	scanf("%d", &N);
	list=(coordinate *)malloc(N*sizeof(coordinate));
	scanf("%d%d", &A, &B);

	for(int n=0;n<N;n++)
		scanf("%d%d", &list[n].x, &list[n].y);
	qsort((void *)list,(size_t)N,sizeof(coordinate),compare);

	for(int n=0;n<N;n++)
	{
		int left=n+1, right=N-1, mid;

		while(left<=right)
		{
			mid=(left+right)>>1;

			if(list[mid].x<list[n].x+A || (list[mid].x==list[n].x+A && list[mid].y<list[n].y))
				left=mid+1;
			else if(list[mid].x>list[n].x+A || (list[mid].x==list[n].x+A && list[mid].y>list[n].y))
				right=mid-1;
			else
				break;
		}
		mid=(left+right)>>1;
		if(list[n].x+A!=list[mid].x || list[n].y!=list[mid].y)
			continue;

		left=n+1;
		right=N-1;
		while(left<=right)
		{
			mid=(left+right)>>1;

			if(list[mid].x<list[n].x+A || (list[mid].x==list[n].x+A && list[mid].y<list[n].y+B))
				left=mid+1;
			else if(list[mid].x>list[n].x+A || (list[mid].x==list[n].x+A && list[mid].y>list[n].y+B))
				right=mid-1;
			else
				break;
		}
		mid=(left+right)>>1;
		if(list[n].x+A!=list[mid].x || list[n].y+B!=list[mid].y)
			continue;

		left=n+1;
		right=N-1;
		while(left<=right)
		{
			mid=(left+right)>>1;

			if(list[mid].x<list[n].x || (list[mid].x==list[n].x && list[mid].y<list[n].y+B))
				left=mid+1;
			else if(list[mid].x>list[n].x || (list[mid].x==list[n].x && list[mid].y>list[n].y+B))
				right=mid-1;
			else
				break;
		}
		mid=(left+right)>>1;
		if(list[n].x==list[mid].x && list[n].y+B==list[mid].y)
			count++;
	}

	printf("%d\n", count);
	free(list);
	return 0;
}