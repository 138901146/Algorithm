#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, *x=NULL, left=0, right, max=0, min;

	scanf("%d", &N);
	x=(int *)malloc(N*sizeof(int));

	for(int n=0;n<N;n++)
		scanf("%d", &x[n]);

	right=N-1;

	while(left<right)
		if(x[left]<x[right])
		{
			max=(right-left-1)*x[left]>max?(right-left-1)*x[left]:max;
			left++;
		}
		else
		{
			max=(right-left-1)*x[right]>max?(right-left-1)*x[right]:max;
			right--;
		}

	printf("%d\n", max);
	free(x);
	return 0;
}