#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

int main(void)
{
	int n, *a=NULL, x, count=0;
	bool *exist=NULL;

	scanf("%d", &n);
	a=(int *)malloc(n*sizeof(int));
	exist=(bool *)calloc(1000001,sizeof(bool));

	for(int i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
		exist[a[i]]=true;
	}

	scanf("%d", &x);

	for(int i=0;i<n;i++)
		if(x-a[i]>a[i] && x-a[i]>0 && x-a[i]<=1000000 && exist[x-a[i]])
			count++;

	printf("%d\n", count);
	free(a);
	free(exist);
	return 0;
}