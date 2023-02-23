#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int n, *box=NULL, *count=NULL, max=0;

	scanf("%d", &n);
	box=(int *)malloc(n*sizeof(int));
	count=(int *)calloc(n,sizeof(int));

	for(int i=0;i<n;i++)
		scanf("%d", &box[i]);

	for(int i=0;i<n;i++)
	{
		count[i]=1;

		for(int j=0;j<i;j++)
			if(box[j]<box[i] && count[i]<=count[j])
				count[i]=count[j]+1;

		max=count[i]>max?count[i]:max;
	}

	printf("%d\n", max);
	free(count);
	free(box);
	return 0;
}