#include<stdio.h>

int pq[101], size=1;

int get(void)
{
	int index=1;

	pq[0]=pq[1];
	pq[1]=pq[--size];

	while(index<size)
	{
		int left=index<<1, right=left|1, next=right<size?pq[left]<pq[right]?left:right:right==size?left:index;

		if(pq[index]<=pq[next])
			break;

		int temp=pq[index];
		pq[index]=pq[next];
		pq[next]=temp;
		index=next;
	}

	return pq[0];
}

void add(int value)
{
	int index=size;

	pq[size++]=value;

	while(index>1)
	{
		int next=index>>1;

		if(pq[next]<=pq[index])
			break;

		pq[0]=pq[index];
		pq[index]=pq[next];
		pq[next]=pq[0];
	}
}

int main(void)
{
	int N, x, y, score=0;

	scanf("%d", &N);

	while(N--)
	{
		scanf("%d", &x);
		add(x);
	}

	while(size>2)
	{
		x=get();
		y=get();
		add(x+y);
		score+=x*y;
	}

	printf("%d", score);
	return 0;
}