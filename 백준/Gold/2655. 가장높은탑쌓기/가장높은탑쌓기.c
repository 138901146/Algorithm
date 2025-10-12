#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int id, area, height, weight;
}
specification;

typedef struct
{
	int height, previous;
}
best;

int compare_by_area(const void *x,const void *y)
{
	return ((specification *)x)->area<((specification *)y)->area?1:-1;
}

int compare_by_weight(const void *x,const void *y)
{
	return ((specification *)x)->weight<((specification *)y)->weight?1:-1;
}

int main(void)
{
	int size, max=0, count=1, start, current, is_area_higher=1;
	specification brick[100];
	best area[100], weight[100];

	scanf("%d", &size);
	for(int i=0;i<size;++i)
	{
		scanf("%d%d%d", &brick[i].area, &brick[i].height, &brick[i].weight);
		brick[i].id=i+1;
	}

	qsort((void *)brick,(size_t)size,sizeof(specification),compare_by_area);
	for(int i=0;i<size;++i)
	{
		area[i].height=0;
		area[i].previous=i;
		for(int j=0;j<i;++j)
			if(brick[i].weight<brick[j].weight&&area[i].height<area[j].height)
			{
				area[i].height=area[j].height;
				area[i].previous=j;
			}
		area[i].height+=brick[i].height;
		max=area[i].height<max?max:area[i].height;
	}

	qsort((void *)brick,(size_t)size,sizeof(specification),compare_by_weight);
	for(int i=0;i<size;++i)
	{
		weight[i].height=0;
		weight[i].previous=i;
		for(int j=0;j<i;++j)
			if(brick[i].area<brick[j].area&&weight[i].height<weight[j].height)
			{
				weight[i].height=weight[j].height;
				weight[i].previous=j;
			}
		weight[i].height+=brick[i].height;
		if(max<=weight[i].height)
		{
			max=weight[i].height;
			is_area_higher=0;
		}
	}

	if(is_area_higher)
	{
		qsort((void *)brick,(size_t)size,sizeof(specification),compare_by_area);
		for(int i=size-1;0<=i;--i)
			if(area[i].height==max)
			{
				current=start=i;
				break;
			}

		while(current!=area[current].previous)
		{
			++count;
			current=area[current].previous;
		}

		current=start;
		printf("%d", count);
		while(current!=area[current].previous)
		{
			printf("\n%d", brick[current].id);
			current=area[current].previous;
		}
		printf("\n%d", brick[current].id);
	}
	else
	{
		for(int i=size-1;0<=i;--i)
			if(weight[i].height==max)
			{
				current=start=i;
				break;

			}

		while(current!=weight[current].previous)
		{
			++count;
			current=weight[current].previous;
		}

		current=start;
		printf("%d", count);
		while(current!=weight[current].previous)
		{
			printf("\n%d", brick[current].id);
			current=weight[current].previous;
		}
		printf("\n%d", brick[current].id);
	}

	return 0;
}