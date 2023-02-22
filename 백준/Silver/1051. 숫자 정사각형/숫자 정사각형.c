#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, M, **rectangle=NULL, maxmax=0;

	scanf("%d %d", &N, &M);
	rectangle=(int **)malloc(N*sizeof(int *));
	for(int n=0;n<N;n++)
		rectangle[n]=(int *)malloc(M*sizeof(int));

	for(int n=0;n<N;n++)
		for(int m=0;m<M;m++)
			scanf("%1d", &rectangle[n][m]);

	for(int n=0;n<N;n++)
		for(int m=0,max=0;m<M;m++,max=0)
			while(n+max<N && m+max<M)
			{
				if(rectangle[n][m]==rectangle[n][m+max] && rectangle[n][m]==rectangle[n+max][m] && rectangle[n][m]==rectangle[n+max][m+max] && max>maxmax)
					maxmax=max;
				max++;
			}

	printf("%d\n", (maxmax+1)*(maxmax+1));
	for(int n=0;n<N;n++)
		free(rectangle[n]);
	free(rectangle);
	return 0;
}