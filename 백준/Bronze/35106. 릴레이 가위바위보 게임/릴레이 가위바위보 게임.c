#include<stdio.h>

int main(void)
{
	int N, select, count[4]={0}, more, less;

	scanf("%d", &N);

	for(int i=0;i<3*N;++i)
	{
		scanf("%d", &select);
		++count[select];
	}

	for(int i=1;i<4;++i)
	{
		int available=1;

		for(int j=1;j<4;++j)
			if(count[j]<count[i])
			{
				available=0;
				break;
			}

		if(available)
			less=i;

		available=1;

		for(int j=1;j<4;++j)
			if(count[i]<count[j])
			{
				available=0;
				break;
			}

		if(available)
			more=i;
	}

	printf("%d\n%d", less, more);
	return 0;
}