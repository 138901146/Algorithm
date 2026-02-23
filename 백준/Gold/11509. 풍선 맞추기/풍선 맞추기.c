#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, *H=NULL, *current=NULL, count=0;

	scanf("%d", &N);

	H=(int *)malloc(N*sizeof(int));
	current=(int *)calloc(1000001,sizeof(int));

	for(int i=0;i<N;++i)
		scanf("%d", &H[i]);

	for(int i=0;i<N;++i)
		if(current[H[i]])
		{
			--current[H[i]];
			if(1<H[i])
				++current[H[i]-1];
		}
		else
		{
			++count;
			if(1<H[i])
				++current[H[i]-1];
		}

	printf("%d", count);
	free(current);
	free(H);
	return 0;
}