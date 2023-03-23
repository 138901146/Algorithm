#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x>*(int *)y?1:*(int *)x==*(int *)y?0:-1;
}

int main(void)
{
	int n, *a=NULL, x, left=0, right, count=0;

	scanf("%d", &n);
	a=(int *)malloc(n*sizeof(int));
	right=n-1;

	for(int i=0;i<n;i++)
		scanf("%d", &a[i]);
	qsort((void *)a,(size_t)n,sizeof(int),compare);

	scanf("%d", &x);

	while(left<right)
		if(a[left]+a[right]==x)
		{
			count++;
			if(a[left]==a[left+1])
				left++;
			else
				right--;
		}
		else if(a[left]+a[right]<x)
			left++;
		else
			right--;

	printf("%d\n", count);
	free(a);
	return 0;
}