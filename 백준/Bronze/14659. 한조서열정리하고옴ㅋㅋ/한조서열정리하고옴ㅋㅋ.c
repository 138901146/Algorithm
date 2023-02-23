#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, *peak=NULL, max=0;

	scanf("%d", &N);
	peak=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;i++)
		scanf("%d", &peak[i]);

	for(int i=0;i<N;i++)
		for(int j=i+1;peak[i]>peak[j] && j<N;j++)
			max=j-i>max?j-i:max;

	printf("%d\n", max);

	free(peak);
	return 0;
}