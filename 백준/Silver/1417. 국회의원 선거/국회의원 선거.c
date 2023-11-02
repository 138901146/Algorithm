#include<stdio.h>

int pq[50], size=1;

int get(void)
{
	int index=1;
	pq[0]=pq[1];
	pq[1]=pq[--size];

	while(index<size)
	{
		int left=index<<1, right=left|1, next=right<size?pq[left]>pq[right]?left:right:right==size?left:index;

		if(pq[index]>=pq[next])
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

		if(pq[index]<=pq[next])
			break;

		int temp=pq[index];
		pq[index]=pq[next];
		pq[next]=temp;
		index=next;
	}
}

int main(void)
{
	int N, dasom, pick, count=0;

	scanf("%d", &N);

	if(N==1)
	{
		printf("0");
		return 0;
	}

	scanf("%d", &dasom);
	while(--N)
	{
		scanf("%d", &pick);
		add(pick);
	}

	while(pq[1]>=dasom)
	{
		int first=get();
		++dasom;
		++count;
		add(first-1);
	}

	printf("%d", count);
	return 0;
}