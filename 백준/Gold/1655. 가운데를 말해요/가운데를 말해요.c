#include<stdio.h>
#include<malloc.h>

int *big=NULL, *small=NULL, big_size=1, small_size=1;

int get_big(void)
{
	int index=1;

	big[0]=big[1];
	big[1]=big[--big_size];

	while(index<big_size)
	{
		int left=index<<1, right=left|1, next=right<big_size?big[left]<big[right]?left:right:right==big_size?left:index;

		if(big[index]<=big[next])
			break;
		int temp=big[index];
		big[index]=big[next];
		big[next]=temp;
		index=next;
	}

	return big[0];
}

int get_small(void)
{
	int index=1;

	small[0]=small[1];
	small[1]=small[--small_size];

	while(index<small_size)
	{
		int left=index<<1, right=left|1, next=right<small_size?small[left]>small[right]?left:right:right==small_size?left:index;

		if(small[index]>=small[next])
			break;
		int temp=small[index];
		small[index]=small[next];
		small[next]=temp;
		index=next;
	}

	return small[0];
}

void add_big(int value)
{
	int index=big_size;

	big[big_size++]=value;

	while(index>1)
	{
		int next=index>>1;

		if(big[next]<=big[index])
			break;
		int temp=big[next];
		big[next]=big[index];
		big[index]=temp;
		index=next;
	}
}

void add_small(int value)
{
	int index=small_size;

	small[small_size++]=value;

	while(index>1)
	{
		int next=index>>1;

		if(small[next]>=small[index])
			break;
		int temp=small[next];
		small[next]=small[index];
		small[index]=temp;
		index=next;
	}
}

int main(void)
{
	int N, value;

	scanf("%d", &N);
	big=(int *)malloc((N+1)*sizeof(int));
	small=(int *)malloc((N+1)*sizeof(int));
	big[1]=100000;

	while(N--)
	{
		scanf("%d", &value);

		if(big_size==small_size)
			add_small(value);
		else
			add_big(value);

		while(big[1]<small[1])
		{
			add_big(get_small());
			add_small(get_big());
		}

		printf("%d\n", small[1]);
	}

	free(big);
	free(small);
	return 0;
}