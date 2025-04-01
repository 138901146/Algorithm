#include<stdio.h>

long long big[20001], small[20001], big_size, small_size;

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
		int left=index<<1, right=left|1, next=right<small_size?small[left]<small[right]?right:left:right==small_size?left:index;

		if(small[next]<=small[index])
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

	while(1<index)
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

	while(1<index)
	{
		int next=index>>1;

		if(small[index]<=small[next])
			break;

		int temp=small[next];
		small[next]=small[index];
		small[index]=temp;
		index=next;
	}
}

int main(void)
{
	int T, M, number;

	scanf("%d", &T);

	while(T--)
	{
		scanf("%d", &M);
		printf("%d\n", M+1>>1);

		big[1]=9876543210;
		big_size=small_size=1;

		for(int m=0;m<M;++m)
		{
			scanf("%d", &number);

			if(big_size==small_size)
				add_small(number);
			else
				add_big(number);

			while(big[1]<small[1])
			{
				add_big(get_small());
				add_small(get_big());
			}

			if(!(m&1))
				printf("%lld ", small[1]);
			if(m%20==19)
				printf("\n");
		}
		if(M%20<19)
			printf("\n");
	}

	return 0;
}