#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>

int main(void)
{
	int N, K, B, broken, min;
	bool *light=NULL;

	scanf("%d%d%d", &N, &K, &B);
	light=(bool *)calloc(N,sizeof(bool));

	while(B--)
	{
		scanf("%d", &broken);
		light[broken-1]=true;
	}

	broken=0;
	for(int i=0;i<K;++i)
		broken+=light[i];
	min=broken;

	for(int i=K;i<N;++i)
	{
		broken-=light[i-K];
		broken+=light[i];
		min=broken<min?broken:min;
	}

	printf("%d", min);
	free(light);
	return 0;
}