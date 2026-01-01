#include<stdio.h>

int main(void)
{
	int N, a, b, max=0, shift;

	scanf("%d", &N);
	scanf("%d%d", &a, &b);

	shift=1<<N;

	for(int x=0;x<shift;++x)
	{
		int count_a=0;

		for(int i=0;i<N;++i)
			count_a+=((1<<i)&x)!=0;

		if(count_a!=a)
			continue;

		for(int y=0;y<shift;++y)
		{
			int count_b=0;

			for(int i=0;i<N;++i)
				count_b+=((1<<i)&y)!=0;

			if(count_b!=b)
				continue;

			max=(x^y)<max?max:(x^y);
		}
	}

	printf("%d", max);
	return 0;
}