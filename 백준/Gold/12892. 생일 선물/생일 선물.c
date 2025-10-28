#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int P, V;
}
present;

int compare(const void *x,const void *y)
{
	return ((present *)x)->P<((present *)y)->P?-1:1;
}

int main(void)
{
	int N, D, left=0;
	present *birthday=NULL;
	long long total=0, max=0;

	scanf("%d%d", &N, &D);
	birthday=(present *)malloc(N*sizeof(present));

	for(int n=0;n<N;++n)
		scanf("%d%d", &birthday[n].P, &birthday[n].V);
	qsort((void *)birthday,(size_t)N,sizeof(present),compare);

	for(int right=0;right<N;++right)
	{
		total+=birthday[right].V;

		while(D<=birthday[right].P-birthday[left].P)
			total-=birthday[left++].V;

		max=total<max?max:total;
	}

	printf("%lld", max);
	free(birthday);
	return 0;
}