#include<stdio.h>

int main(void)
{
	int N, M, h1, h2, hand[10001]={0}, count=0;

	scanf("%d%d", &N, &M);

	for(int m=1;m<=M;++m)
	{
		scanf("%d%d", &h1, &h2);
		hand[h1]=hand[h2]=m;
	}

	N%=(M<<1);
	if(!N)
		N+=M<<1;

	for(int i=1;i<10001;++i)
		if(hand[i] && ++count==N)
		{
			printf("%d", hand[i]);
			return 0;
		}

	return 0;
}