#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int K, *money=NULL, sum=0, state=0;

	scanf("%d", &K);
	money=(int *)calloc(K,sizeof(int));

	for(int i=0;i<K;i++)
	{
		scanf("%d", &money[state]);

		state+=money[state]==0?-1:1;
	}

	for(int i=0;i<state;i++)
		sum+=money[i];

	printf("%d\n", sum);

	free(money);
	return 0;
}