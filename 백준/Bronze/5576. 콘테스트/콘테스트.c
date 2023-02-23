#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x>*(int *)y?1:*(int *)x==*(int *)y?0:-1;
}

int main(void)
{
	int W[10], K[10];

	for(int w=0;w<10;w++)
		scanf("%d", &W[w]);
	for(int k=0;k<10;k++)
		scanf("%d", &K[k]);

	qsort((void *)W,(size_t)10,sizeof(int),compare);
	qsort((void *)K,(size_t)10,sizeof(int),compare);

	printf("%d %d\n", W[7]+W[8]+W[9], K[7]+K[8]+K[9]);
	return 0;
}