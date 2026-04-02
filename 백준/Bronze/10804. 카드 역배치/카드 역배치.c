#include<stdio.h>

int main(void)
{
	int card[21], a, b, temp[21];

	for(int i=1;i<21;++i)
		card[i]=i;

	for(int i=0;i<10;++i)
	{
		scanf("%d%d", &a, &b);

		for(int j=0;j<=b-a;++j)
			temp[b-j]=card[a+j];

		for(int j=a;j<=b;++j)
			card[j]=temp[j];
	}

	for(int i=1;i<21;++i)
		printf("%d ", card[i]);
	return 0;
}