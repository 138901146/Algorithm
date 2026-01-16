#include<stdio.h>
#include<stdlib.h>

#define INF 2000000000

typedef struct
{
	int S, E, C;
}
route;

int compare(const void *x,const void *y)
{
	return ((route *)x)->S<((route *)y)->S?-1:1;
}

int main(void)
{
	int N, K=0, S, E, C;
	route *origin=NULL, *renew=NULL;

	scanf("%d", &N);

	origin=(route *)malloc(N*sizeof(route));
	renew=(route *)malloc(N*sizeof(route));

	for(int i=0;i<N;++i)
		scanf("%d%d%d", &origin[i].S, &origin[i].E, &origin[i].C);

	qsort((void *)origin,(size_t)N,sizeof(route),compare);

	renew[0].S=origin[0].S;
	renew[0].E=origin[0].E;
	renew[0].C=origin[0].C;
	for(int i=1;i<N;++i)
	{
		if(renew[K].E<origin[i].S)
		{
			renew[++K].S=origin[i].S;
			renew[K].E=origin[i].E;
			renew[K].C=origin[i].C;
		}
		else
		{
			renew[K].C=renew[K].C<origin[i].C?renew[K].C:origin[i].C;
			renew[K].E=renew[K].E<origin[i].E?origin[i].E:renew[K].E;
		}
	}

	printf("%d", ++K);
	for(int i=0;i<K;++i)
		printf("\n%d %d %d", renew[i].S, renew[i].E, renew[i].C);

	free(origin);
	free(renew);

	return 0;
}