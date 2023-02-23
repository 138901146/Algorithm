#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int M, N, *friends=NULL, *target=NULL;

	scanf("%d", &N);
	friends=(int *)calloc(N,sizeof(int));

	scanf("%d", &M);
	target=(int *)malloc(M*sizeof(int));

	for(int i=0;i<M;i++)
		scanf("%d", &target[i]);

	for(int i=0;i<M;i++)
	{
		int count=N;

		for(int j=0;j<N;j++)
		{
			int choice;

			scanf("%d", &choice);

			if(target[i]==choice)
			{
				friends[j]++;
				count--;
			}
		}

		friends[target[i]-1]+=count;
	}

	for(int j=0;j<N;j++)
		printf("%d\n", friends[j]);

	free(friends);
	free(target);
	return 0;
}