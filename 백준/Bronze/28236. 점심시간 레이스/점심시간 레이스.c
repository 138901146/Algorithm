#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int n, m, k, *f=NULL, *d=NULL, min=0;

	scanf("%d%d%d", &n, &m, &k);
	f=(int *)malloc(k*sizeof(int));
	d=(int *)malloc(k*sizeof(int));

	for(int i=0;i<k;++i)
		scanf("%d%d", &f[i], &d[i]);

	for(int i=1;i<k;++i)
		if(f[i]-d[i]<f[min]-d[min])
			min=i;

	printf("%d", min+1);
	free(f);
	free(d);
	return 0;
}