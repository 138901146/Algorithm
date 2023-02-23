#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x>*(int *)y?1:*(int *)x==*(int *)y?0:-1;
}

int main(void)
{
	int N, *permutation=NULL, index, *to_change=NULL, last;

	scanf("%d", &N);
	permutation=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;i++)
		scanf("%d", &permutation[i]);

	index=N-2;

	while(index>=0 && permutation[index]>permutation[index+1])
		index--;

	if(index<0 || N==1)
	{
		printf("-1\n");
		free(permutation);
		return 0;
	}

	to_change=(int *)malloc((N-index)*sizeof(int));
	for(int i=index;i<N;i++)
		to_change[i-index]=permutation[i];
	qsort((void *)to_change,(size_t)N-index,sizeof(int),compare);

	last=N-index-1;
	for(int i=index;i<N;i++)
		if(to_change[i-index]>permutation[index])
			last=to_change[i-index]<to_change[last]?i-index:last;

	int temp=to_change[last];
	for(int i=last;i>0;i--)
		to_change[i]=to_change[i-1];
	to_change[0]=temp;
	for(int i=index;i<N;i++)
		permutation[i]=to_change[i-index];

	for(int i=0;i<N;i++)
		printf("%d ", permutation[i]);
	printf("\n");

	free(permutation);
	free(to_change);
	return 0;
}
