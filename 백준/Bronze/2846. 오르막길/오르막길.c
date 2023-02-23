#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, *road=NULL, up=0, max=0;

	scanf("%d", &N);
	road=(int *)malloc(N*sizeof(int));

	for(int n=0;n<N;n++)
		scanf("%d", &road[n]);

	for(int n=1;n<N;n++)
		if(road[n]-road[n-1]>0)
		{
			up+=road[n]-road[n-1];
			max=up>max?up:max;
		}
		else
			up=0;

	printf("%d\n", max);
	free(road);
	return 0;
}