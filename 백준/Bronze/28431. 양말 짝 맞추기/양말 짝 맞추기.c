#include<stdio.h>

int main(void)
{
	int pairs[10]={0}, socks;

	for(int i=0;i<5;++i)
	{
		scanf("%d", &socks);
		++pairs[socks];
	}

	for(int i=0;i<10;++i)
		if(pairs[i]&1)
			printf("%d", i);

	return 0;
}