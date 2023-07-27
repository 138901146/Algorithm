#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, C, *button=NULL, min_index=0;
	unsigned long long *left=NULL, *right=NULL, max, bigger;

	scanf("%d%d", &N, &C);
	button=(int *)malloc((N+1)*sizeof(int));
	left=(unsigned long long *)calloc(N,sizeof(unsigned long long));
	right=(unsigned long long *)calloc(N,sizeof(unsigned long long));

	for(int n=0;n<N;n++)
		scanf("%d", &button[n]);

	for(int i=1;i<N;i++)
		if(button[i]<=button[i-1])
			left[i]=left[i-1]+button[i-1]-button[i];
		else
			left[i]=left[i-1]+C+button[i-1]-button[i];

	for(int i=N-2;i>=0;i--)
		if(button[i]<=button[i+1])
			right[i]=right[i+1]+button[i+1]-button[i];
		else
			right[i]=right[i+1]+C+button[i+1]-button[i];

	max=left[0]<right[0]?right[0]:left[0];
	for(int i=1;i<N;i++)
	{
		bigger=left[i]<right[i]?right[i]:left[i];
		if(bigger<max)
		{
			max=bigger;
			min_index=i;
		}
	}

	printf("%d\n%llu\n", min_index+1, max);
	free(button);
	free(left);
	free(right);
	return 0;
}