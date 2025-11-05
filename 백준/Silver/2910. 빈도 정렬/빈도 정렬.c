#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int number, index, count;
}
frequency;

int compare(const void *x,const void *y)
{
	return ((frequency *)x)->count<((frequency *)y)->count?1:((frequency *)y)->count<((frequency *)x)->count?-1:((frequency *)x)->index<((frequency *)y)->index?-1:1;
}

int main(void)
{
	int N, C, duplicate=0;
	frequency *message=NULL;

	scanf("%d%d", &N, &C);
	message=(frequency *)calloc(N,sizeof(frequency));

	for(int i=0;i<N;++i)
	{
		scanf("%d", &message[i-duplicate].number);

		message[i-duplicate].index=i;
		message[i-duplicate].count=1;

		for(int j=0;j<i-duplicate;++j)
			if(message[i-duplicate].number==message[j].number)
			{
				++message[j].count;
				++duplicate;
				break;
			}
	}

	qsort((void *)message,(size_t)N-duplicate,sizeof(frequency),compare);

	for(int i=0;i<N-duplicate;++i)
		for(int j=0;j<message[i].count;++j)
			printf("%d ", message[i].number);
	free(message);
	return 0;
}