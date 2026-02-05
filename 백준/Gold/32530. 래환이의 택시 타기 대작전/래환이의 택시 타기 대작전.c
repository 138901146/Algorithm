#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x<*(int *)y?-1:1;
}

int main(void)
{
	int N, H, M, *list=NULL, count=0, done=0;

	scanf("%d", &N);

	list=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;++i)
	{
		scanf("%02d:%02d", &H, &M);
		list[i]=H*60+M;
	}

	qsort((void *)list,(size_t)N,sizeof(int),compare);

	while(done<N)
	{
		if(done+2<N&&list[done+2]-list[done]<21)
			done+=3;
		else if(done+1<N&&list[done+1]-list[done]<21)
			done+=2;
		else
			++done;

		++count;
	}

	printf("%d", count);
	free(list);
	return 0;
}