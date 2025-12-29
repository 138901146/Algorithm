#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, *book=NULL, count, index, current;

	scanf("%d", &N);
	book=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;++i)
		scanf("%d", &book[i]);

	current=N-1;
	for(int i=0;i<N;++i)
		if(book[i]==N)
		{
			index=i;
			break;
		}

	count=N-index-1;
	while(0<index)
	{
		if(book[index-1]!=current)
			++count;
		else
			--current;
		--index;
	}

	printf("%d", count);
	free(book);
	return 0;
}