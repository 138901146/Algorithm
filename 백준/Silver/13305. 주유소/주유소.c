#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int index, price, done;
}
structure;

int compare(const void *x,const void *y)
{
	return ((structure *)x)->price<((structure *)y)->price?-1:((structure *)x)->price>((structure *)y)->price?1:((structure *)x)->index<((structure *)y)->index?-1:1;
}

int main(void)
{
	int N, left;
	structure *oil_bank=NULL;
	long long total=0;

	scanf("%d", &N);
	oil_bank=(structure *)malloc(N*sizeof(structure));

	oil_bank[0].done=0;
	for(int i=1;i<N;++i)
	{
		scanf("%d", &oil_bank[i].done);
		oil_bank[i].done+=oil_bank[i-1].done;
	}

	for(int i=0;i<N;++i)
	{
		scanf("%d", &oil_bank[i].price);
		oil_bank[i].index=i;
	}

	left=oil_bank[N-1].done;
	qsort((void *)oil_bank,(size_t)N,sizeof(structure),compare);

	for(int i=0;i<N && left;++i)
		if(oil_bank[i].done<left)
		{
			total+=(long long)oil_bank[i].price*(left-oil_bank[i].done);
			left=oil_bank[i].done;
		}

	printf("%lld", total);
	free(oil_bank);
	return 0;
}