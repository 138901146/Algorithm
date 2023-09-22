#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
	int korean, english, math;
	char name[11];
}
student;

int compare(const void *x,const void *y)
{
	return ((student *)x)->korean<((student *)y)->korean || ((student *)x)->korean==((student *)y)->korean&&((student *)x)->english>((student *)y)->english || ((student *)x)->korean==((student *)y)->korean&&((student *)x)->english==((student *)y)->english&&((student *)x)->math<((student *)y)->math || ((student *)x)->korean==((student *)y)->korean&&((student *)x)->english==((student *)y)->english&&((student *)x)->math==((student *)y)->math&&strcmp(((student *)x)->name,((student *)y)->name)>0?1:-1;
}

int main(void)
{
	int N;
	student *dohyun=NULL;

	scanf("%d", &N);
	dohyun=(student *)malloc(N*sizeof(student));

	for(int i=0;i<N;++i)
		scanf("%s%d%d%d", dohyun[i].name, &dohyun[i].korean, &dohyun[i].english, &dohyun[i].math);

	qsort((void *)dohyun,(size_t)N,sizeof(student),compare);

	for(int i=0;i<N;++i)
		printf("%s\n", dohyun[i].name);
	free(dohyun);
	return 0;
}