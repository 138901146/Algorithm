#include<stdio.h>

int main(void)
{
	int N, i, count[51]={0}, max=-1;

	scanf("%d", &N);

	while(N--)
	{
		scanf("%d", &i);
		++count[i];
	}

	for(i=0;i<51;++i)
		max=count[i]==i?i:max;

	printf("%d", max);
	return 0;
}