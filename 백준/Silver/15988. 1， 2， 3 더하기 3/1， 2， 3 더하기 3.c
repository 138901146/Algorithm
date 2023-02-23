#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	unsigned int T, n, *way=calloc(1000001,sizeof(unsigned int));

	way[0]=0;
	way[1]=1;
	way[2]=2;
	way[3]=4;
	for(int w=4;w<1000001;w++)
		way[w]=(way[w-1]+way[w-2]+way[w-3])%1000000009;

	scanf("%u", &T);

	for(int t=0;t<T;t++)
	{
		scanf("%u", &n);
		printf("%u\n", way[n]);
	}

	free(way);
	return 0;
}