#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
	char mento[21], menti[21];
}
pair;

int compare(const void *x,const void *y)
{
	return strcmp(((pair *)x)->mento,((pair *)y)->mento)?strcmp(((pair *)x)->mento,((pair *)y)->mento):strcmp(((pair *)y)->menti,((pair *)x)->menti);
}

int main(void)
{
	int N;
	pair *list=NULL;

	scanf("%d", &N);
	list=(pair *)calloc(N,sizeof(pair));

	for(int n=0;n<N;++n)
		scanf("%s%s", list[n].mento, list[n].menti);
	qsort((void *)list,(size_t)N,sizeof(pair),compare);

	for(int n=0;n<N;++n)
		printf("%s %s\n", list[n].mento, list[n].menti);
	free(list);
	return 0;
}