#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(long long *)x>*(long long *)y?1:-1;
}

int main(void)
{
	int N, count=1, max=1;
	long long *card=NULL, number;

	scanf("%d", &N);
	card=(long long *)malloc(N*sizeof(long long));

	for(int n=0;n<N;n++)
		scanf("%lld", &card[n]);

	qsort((void *)card,(size_t)N,sizeof(long long),compare);

	number=card[0];

	for(int n=1;n<N;n++)
	{
		if(card[n]==card[n-1])
		{
			count++;
			if(count>max)
			{
				max=count;
				number=card[n];
			}
		}
		else
			count=1;
	}

	printf("%lld\n", number);
	free(card);
	return 0;
}