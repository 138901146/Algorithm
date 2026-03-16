#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>

int main(void)
{
	int n, m, k, child;
	bool *gift=NULL;

	scanf("%d%d%d", &n, &m, &k);
	printf("%d\n", n-m-k);

	gift=(bool *)calloc(n+1,sizeof(bool));

	while(m--)
	{
		scanf("%d", &child);
		gift[child]=true;
	}

	while(k--)
	{
		scanf("%d", &child);
		gift[child]=true;
	}

	for(child=1;child<=n;++child)
		if(!gift[child])
			printf("%d ", child);
	free(gift);
	return 0;
}