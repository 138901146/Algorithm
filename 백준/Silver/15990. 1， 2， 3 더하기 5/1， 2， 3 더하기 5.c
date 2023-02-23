#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	unsigned int **way=malloc(100001*sizeof(unsigned int *)), T, n;
	for(int w=0;w<100001;w++)
		way[w]=(unsigned int *)calloc(3,sizeof(unsigned int));
	way[0][0]=way[0][1]=way[0][2]=0;
	way[1][0]=1;
	way[1][1]=way[1][2]=0;
	way[2][0]=way[2][2]=0;
	way[2][1]=1;
	way[3][0]=way[3][1]=way[3][2]=1;
	for(int w=4;w<100001;w++)
	{
		way[w][0]=(way[w-1][1]+way[w-1][2])%1000000009;
		way[w][1]=(way[w-2][0]+way[w-2][2])%1000000009;
		way[w][2]=(way[w-3][0]+way[w-3][1])%1000000009;
	}

	scanf("%d", &T);

	for(int t=0;t<T;t++)
	{
		scanf("%d", &n);
		printf("%d\n", (way[n][0]+way[n][1]+way[n][2])%1000000009);
	}

	for(int w=0;w<100001;w++)
		free(way[w]);
	free(way);
	return 0;
}