#include<stdio.h>

int N, c[10], discount[10][10]={0}, min=99999, done;

void simulate(int current,int flag,int total)
{
	int price=c[current];

	for(int i=0;i<N;++i)
		if(1<<i&flag)
			price-=discount[i][current];

	price=price<1?1:price;

	if(flag==done)
	{
		min=total+price<min?total+price:min;
		return;
	}

	for(int i=0;i<N;++i)
		if(!(1<<i&flag))
			simulate(i,1<<i|flag,total+price);
}

int main(void)
{
	scanf("%d", &N);
	for(int i=0;i<N;++i)
		scanf("%d", &c[i]);

	for(int i=0;i<N;++i)
	{
		int p, a, d;

		scanf("%d", &p);

		while(p--)
		{
			scanf("%d%d", &a, &d);
			discount[i][--a]=d;
		}
	}

	done=(1<<N)-1;
	for(int i=0;i<N;++i)
		simulate(i,1<<i,0);

	printf("%d", min);
	return 0;
}