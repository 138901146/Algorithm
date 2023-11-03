#include<stdio.h>

int size=1;
long long pq[1001];

long long get(void)
{
	int index=1;
	pq[0]=pq[1];
	pq[1]=pq[--size];

	while(index<size)
	{
		int left=index<<1, right=left|1, next=right<size?pq[left]<pq[right]?left:right:right==size?left:index;

		if(pq[index]<=pq[next])
			break;

		long long temp=pq[index];
		pq[index]=pq[next];
		pq[next]=temp;
		index=next;
	}

	return pq[0];
}

void add(long long value)
{
	int index=size;
	pq[size++]=value;

	while(index>1)
	{
		int next=index>>1;

		if(pq[index]>=pq[next])
			break;

		pq[0]=pq[index];
		pq[index]=pq[next];
		pq[next]=pq[0];
		index=next;
	}
}

int main(void)
{
	int n, m;
	long long a, x, y, score=0;

	scanf("%d%d", &n, &m);
	for(int i=0;i<n;++i)
	{
		scanf("%lld", &a);
		add(a);
	}

	while(m--)
	{
		x=get();
		y=get();

		x+=y;

		add(x);
		add(x);
	}

	for(int i=1;i<=n;++i)
		score+=pq[i];

	printf("%lld", score);
	return 0;
}