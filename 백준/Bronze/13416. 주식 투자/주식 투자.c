#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int T;

	scanf("%d", &T);
	for(int t=0;t<T;t++)
	{
		int N, **pl=malloc(3*sizeof(int *)), sum=0;

		scanf("%d", &N);
		for(int days=0;days<3;days++)
			pl[days]=(int *)malloc(N*sizeof(int));

		for(int days=0;days<N;days++)
		{
			int max=0;

			for(int i=0;i<3;i++)
			{
				scanf("%d", &pl[i][days]);
				max=pl[i][days]>max?pl[i][days]:max;
			}
			sum+=max;
		}

		printf("%d\n", sum);
		for(int days=0;days<3;days++)
			free(pl[days]);
		free(pl);
	}

	return 0;
}