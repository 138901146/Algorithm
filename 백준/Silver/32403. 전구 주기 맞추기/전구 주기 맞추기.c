#include<stdio.h>

int main(void)
{
	int N, T, a[1000], total=0;

	scanf("%d%d", &N, &T);
	for(int i=0;i<N;++i)
		scanf("%d", &a[i]);

	for(int i=0;i<N;++i)
	{
		int low=a[i]+1, high=a[i]-1, count=-1;

		while(1)
		{
			--low;
			++high;
			++count;

			if(0<low&&T%low==0)
				break;
			if(high<=T&&T%high==0)
				break;
		}

		total+=count;
	}

	printf("%d", total);
	return 0;
}