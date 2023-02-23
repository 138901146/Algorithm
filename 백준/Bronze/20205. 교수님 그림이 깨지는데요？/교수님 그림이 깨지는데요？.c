#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, K, **image=NULL;

	scanf("%d %d", &N, &K);
	image=(int **)malloc(N*sizeof(int *));
	for(int n=0;n<N;n++)
		image[n]=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			scanf("%d", &image[i][j]);

	for(int i=0;i<N;i++)
		for(int ki=0;ki<K;ki++)
		{
			for(int j=0;j<N;j++)
				for(int kj=0;kj<K;kj++)
					printf("%d ", image[i][j]);
			printf("\n");
		}
	for(int n=0;n<N;n++)
		free(image[n]);
	free(image);
	return 0;
}