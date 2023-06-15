#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int W, H, *block=NULL, *prefix=NULL, *suffix=NULL, sum=0;

	scanf("%d%d", &H, &W);
	block=(int *)malloc((W+1)*sizeof(int));
	prefix=(int *)calloc(W+2,sizeof(int));
	suffix=(int *)calloc(W+2,sizeof(int));

	for(int i=1;i<=W;i++)
	{
		scanf("%d", &block[i]);
		prefix[i]=block[i]>prefix[i-1]?block[i]:prefix[i-1];
	}
	for(int i=W;i>0;i--)
		suffix[i]=block[i]>suffix[i+1]?block[i]:suffix[i+1];

	for(int i=1;i<=W;i++)
	{
		int min=prefix[i]<suffix[i]?prefix[i]:suffix[i];
		sum+=min-block[i];
	}

	printf("%d\n", sum);
	free(prefix);
	free(suffix);
	free(block);
	return 0;
}
