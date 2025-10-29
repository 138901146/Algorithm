#include<stdio.h>

int main(void)
{
	int N;

	scanf("%d", &N);

	while(N--)
	{
		int V, S, count[1001]={0}, max=0;

		scanf("%d", &V);

		while(V--)
		{
			scanf("%d", &S);
			++count[S];
		}

		for(int i=1;i<1001;++i)
			max=count[max]<count[i]?i:max;

		printf("%d\n", max);
	}

	return 0;
}