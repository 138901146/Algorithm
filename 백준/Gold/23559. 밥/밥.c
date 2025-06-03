#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int A, B;
}
corner;

int compare(const void *x,const void *y)
{
	return ((corner *)x)->A-((corner *)x)->B<((corner *)y)->A-((corner *)y)->B?1:-1;
}

int main(void)
{
	int N, X, max=0, B_available;
	corner *menu=NULL;

	scanf("%d%d", &N, &X);
	menu=(corner *)malloc(N*sizeof(corner));

	for(int n=0;n<N;++n)
		scanf("%d%d", &menu[n].A, &menu[n].B);
	qsort((void *)menu,(size_t)N,sizeof(corner),compare);

	B_available=(X-1000*N)/4000;
	for(int n=0;n<N&&n<B_available;++n)
		max+=menu[n].B<menu[n].A?menu[n].A:menu[n].B;
	for(int n=B_available;n<N;++n)
		max+=menu[n].B;

	printf("%d", max);
	free(menu);
	return 0;
}