#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int x, y;
}
location;

int compare(const void *primary,const void *secondary)
{
	return ((location *)primary)->x<((location *)secondary)->x?-1:((location *)secondary)->x<((location *)primary)->x?1:((location *)primary)->y<((location *)secondary)->y?-1:1;
}

int main(void)
{
	int N, A, B, count=0;
	location *dots=NULL;

	scanf("%d", &N);
	scanf("%d%d", &A, &B);

	dots=(location *)malloc(N*sizeof(location));

	for(int i=0;i<N;++i)
		scanf("%d%d", &dots[i].x, &dots[i].y);

	qsort((void *)dots,(size_t)N,sizeof(location),compare);

	for(int i=0;i<N;++i)
	{
		int left=i, right=N-1, mid;

		while(left<right)
		{
			mid=left+right>>1;

			if(dots[i].x+A<dots[mid].x)
				right=mid-1;
			else if(dots[mid].x<dots[i].x+A)
				left=mid+1;
			else if(dots[i].y<dots[mid].y)
				right=mid-1;
			else if(dots[mid].y<dots[i].y)
				left=mid+1;
			else
				break;
		}

		mid=left+right>>1;

		if(dots[i].x+A!=dots[mid].x||dots[i].y!=dots[mid].y)
			continue;

		left=i;
		right=N-1;

		while(left<right)
		{
			mid=left+right>>1;

			if(dots[i].x+A<dots[mid].x)
				right=mid-1;
			else if(dots[mid].x<dots[i].x+A)
				left=mid+1;
			else if(dots[i].y+B<dots[mid].y)
				right=mid-1;
			else if(dots[mid].y<dots[i].y+B)
				left=mid+1;
			else
				break;
		}

		mid=left+right>>1;

		if(dots[i].x+A!=dots[mid].x||dots[i].y+B!=dots[mid].y)
			continue;

		left=i;
		right=N-1;

		while(left<right)
		{
			mid=left+right>>1;

			if(dots[i].x<dots[mid].x)
				right=mid-1;
			else if(dots[mid].x<dots[i].x)
				left=mid+1;
			else if(dots[i].y+B<dots[mid].y)
				right=mid-1;
			else if(dots[mid].y<dots[i].y+B)
				left=mid+1;
			else
				break;
		}

		mid=left+right>>1;

		if(dots[i].x!=dots[mid].x||dots[i].y+B!=dots[mid].y)
			continue;

		++count;
	}

	printf("%d", count);
	free(dots);
	return 0;
}